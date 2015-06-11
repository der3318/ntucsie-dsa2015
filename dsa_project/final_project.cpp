#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include "md5.h"
extern "C"
{
#include "rb.h"
}	
#define MAX_HASH 1000000
#define MAX_LEN 110
#define MAX_REC 1000000
#define MAX_DATA 1000000
#define MAX_STR_INDEX 100

class Record 
{
	public:
		long long int cash;
		char to[MAX_LEN], from[MAX_LEN];
		Record(){}
		Record(long long int _cash, char *_to, char *_from):   cash(_cash) {   strcpy(to, _to);    strcpy(from, _from);  }
};

class Data
{
	public:
		char account[MAX_LEN];
		MD5 password;
		long long int cash;
		std::vector<int> record;
		Data(){}
		Data(char *_id, MD5& _password, long long int _cash):  password(_password), cash(_cash)    {	strcpy(account, _id);	}
		~Data(){	record.clear();	}
};

class Index
{
	public:
		std::vector<int> index;
};

int cmp_data(const void *pa, const void *pb, void *param)
{
		const char* a = (const char*)pa;
		const char* b = (const char*)pb;
		if(strcmp(a, b) < 0)	return -1;
		else if(strcmp(a, b) > 0)	return +1;
		else return 0;
}

class IDs
{
	public:
		struct rb_table *index;
		IDs()	{	index = rb_create(cmp_data, NULL, NULL);	}
};

Index *hash_table;
Data *data;
int n_record, n_data, current_index, tmp_index;
Record *record; 
IDs *ids;

void push_id(char *_id, int _index)
{
	int *element = (int*)malloc(sizeof(int));
	*element = _index;
	rb_probe(ids[strlen(_id) - 1].index, element);
}

int diff(char *id_1, char *id_2)
{
	int output = strlen(id_1) - strlen(id_2), size = strlen(id_1);
	if(output > 0)	size = strlen(id_2);
	else	output = -output;
	output = (output + 1) * output / 2;
	for(int i = size - 1 ; i >= 0 ; i--)	if(id_1[i] != id_2[i])	output += (size - i);
	return output;
}

void find_in_rb(struct rb_node *node,char *_id, std::pair<int, int> *output, int &n)
{
	if(node == NULL)	return;
	find_in_rb(node->rb_link[0], _id, output, n);
	int index = *((int*)(node->rb_data));
	if(data[index].cash != (long long int)-1)
	{
		int d = diff(_id, data[index].account);
		if(n == 0)	{	output[n].first = d;	output[n++].second = index;	}
		else if(n < 10 || d < output[9].first || (d == output[9].first && strcmp(data[index].account, data[ output[9].second ].account) < 0))
		{
			int i = 0;
			for(i = 0 ; i < n ; i++)
				if(d < output[i].first || (d == output[i].first && strcmp(data[index].account, data[ output[i].second ].account) < 0))
				{
					for(int j = n - 1 ; j >= i ; j--)	output[j + 1] = output[j];
					output[i].first = d;	output[i].second = index;
					if(n < 10)	n++;
					break;
				}
			if(i == n)	{	output[n].first = d;	output[n++].second = index;	}	
		}
	}
	find_in_rb(node->rb_link[1], _id, output, n);
}

void find_10(char *_id)
{
	std::pair<int, int> output[10];
	int index = (strlen(_id) - 1), n = 0, flag = 1, count = 1;
	find_in_rb((ids[index].index)->rb_root, _id, output, n);
	while(n < 10 || output[9].first >= flag)
	{
		int index_left = index - count, index_right = index + count;
		if(index_left <= -1 && index_right >= 100)	break;
		if(index_left > -1)	find_in_rb(ids[index_left].index->rb_root, _id, output, n);
		if(index_right < 100)	find_in_rb(ids[index_right].index->rb_root, _id, output, n);
		count++;	flag += count;
	}
	if(n > 0)	printf(", %s", data[output[0].second].account);
	for(int i = 1 ; i < n ; i++)	printf(",%s", data[output[i].second].account);
	printf("\n");
}

int hashingID(char* _id)
{
	int index = 0, len = strlen(_id);
	for(int i = 0 ; i < len ; i++)
	{
		index *= 71;
		if(_id[i] >= 'a')   index += ((int)(_id[i] - 'a') + 1);
		else if(_id[i] >= 'A')  index += ((int)(_id[i] - 'A') + 27);
		else index += ((int)(_id[i] - '0') + 53);
		index %= MAX_HASH;
	}
	return index;
}

int check(char *id, char* psd)
{
	int index = hashingID(id), size = hash_table[index].index.size(), i = 0;
	for(i = 0 ; i < size ; i++)	if( strcmp(data[ hash_table[index].index[i] ].account, id) == 0 )	break;
	if(i == size)	return -1;
	MD5 psd_md(psd);
	if(data[ hash_table[index].index[i] ].cash == (long long int)-1)	{	tmp_index = hash_table[index].index[i];	return -3;	}
	if(psd_md == data[ hash_table[index].index[i] ].password || psd[0] == '-')  return hash_table[index].index[i];  
	return -2;
}

void merge_rec(int &index_1, int &index_2)
{
	std::vector<int> &r_1 = data[index_1].record, &r_2 = data[index_2].record, new_record;
	int size_1 = r_1.size(), size_2 = r_2.size(), n_1 = 0, n_2 = 0;
	while(n_1 != size_1 && n_2 != size_2)
	{
		if(r_1[n_1] < r_2[n_2])	new_record.push_back(r_1[n_1++]);
		else if (r_1[n_1] > r_2[n_2])
		{
			if( strcmp(record[ r_2[n_2] ].to, data[index_2].account) == 0 )	strcpy(record[ r_2[n_2] ].to, data[index_1].account);
			else strcpy(record[ r_2[n_2] ].from, data[index_1].account);
			new_record.push_back(r_2[n_2++]);
		}
		else
		{
			if( strcmp( record[ r_1[n_1] ].to, data[index_1].account) == 0 )	strcpy(record[ r_1[n_1] ].from, "-");
			else	strcpy(record[ r_1[n_1] ].to, "-");
			new_record.push_back(r_1[n_1++]);
			n_2++;
		}
	}
	while(n_1 != size_1)	new_record.push_back(r_1[n_1++]);
	while(n_2 != size_2)
	{
		if( strcmp(record[ r_2[n_2] ].to, data[index_2].account) == 0 )	strcpy(record[ r_2[n_2] ].to, data[index_1].account);
		if( strcmp(record[ r_2[n_2] ].from, data[index_2].account) == 0 )	strcpy(record[ r_2[n_2] ].from, data[index_1].account);
		new_record.push_back(r_2[n_2++]);
	}
	r_1 = new_record;
}	

void find_rec(int &flag, char *id)
{
	std::vector<int> &r = data[current_index].record;
	int size = r.size(), n = 0, found = 0;
	if(flag == current_index)
		while(n < size)
		{
			if( strcmp(record[ r[n] ].to, "-") == 0 )	{	printf("To %s %lld\nFrom %s %lld\n", id, record[ r[n] ].cash, id, record[ r[n] ].cash);	found = 1;	}
			if( strcmp(record[ r[n] ].from, "-") == 0 )	{	printf("From %s %lld\nTo %s %lld\n", id, record[ r[n] ].cash, id, record[ r[n] ].cash);	found = 1;	}
			n++;
		}
	else
		while(n < size)
		{
			if( strcmp(record[ r[n] ].to, id) == 0 )	{	printf("To %s %lld\n", id, record[ r[n] ].cash);	found = 1;	}
			if( strcmp(record[ r[n] ].from, id) == 0 )	{	printf("From %s %lld\n", id, record[ r[n] ].cash);	found = 1;	}
			n++;
		}
	if(found == 0)	printf("no record\n");
}

void find_10_free(char *_id)
{
	printf("\n");
}

int main()
{
	hash_table = new Index[MAX_HASH];
	record = new Record[MAX_REC];
	data = new Data[MAX_DATA];
	ids = new IDs[MAX_STR_INDEX];
	n_record = 0;
	n_data = 0;
	char cmd[MAX_LEN];
	while(scanf("%s", cmd) != EOF)
	{
		if(strcmp(cmd, "login") == 0)
		{
			char id[MAX_LEN], psd[MAX_LEN];
			scanf("%s %s", id, psd);
			int flag = check(id, psd);
			if(flag == -1 || flag == -3)	printf("ID %s not found\n", id);
			else if(flag == -2) printf("wrong password\n");
			else	{	current_index = flag;	printf("success\n");	}
		}
		else if(strcmp(cmd, "create") == 0)
		{
			char id[MAX_LEN], psd[MAX_LEN];
			scanf("%s %s", id, psd);
			int flag = check(id, psd);
			if(flag == -2 || flag >= 0)  {	printf("ID %s exists", id);	find_10_free(id);	}
			else
			{
				printf("success\n");
				MD5 psd_md(psd);
				Data new_data(id, psd_md, (long long int)0);
				if(flag == -3)	data[tmp_index] = new_data;
				else	{	data[n_data] = new_data;	hash_table[ hashingID(id) ].index.push_back(n_data);	push_id(id, n_data++);	}
			}
		}
		else if(strcmp(cmd, "delete") == 0)
		{
			char id[MAX_LEN], psd[MAX_LEN];
			scanf("%s %s", id, psd);
			int flag = check(id, psd);
			if(flag == -1 || flag == -3)  printf("ID %s not found\n", id);
			else if(flag == -2) printf("wrong password\n");
			else	{	data[flag].cash = (long long int)-1;	printf("success\n");	}
		}
		else if(strcmp(cmd, "merge") == 0)
		{
			char id1[MAX_LEN], psd1[MAX_LEN], id2[MAX_LEN], psd2[MAX_LEN];
			scanf("%s %s %s %s", id1, psd1, id2, psd2);
			int flag_1 = check(id1, psd1), flag_2 = check(id2, psd2);
			if(flag_1 == -1 || flag_1 == -3) printf("ID %s not found\n", id1);
			else if(flag_2 == -1 || flag_2 == -3)    printf("ID %s not found\n", id2);
			else if(flag_1 == -2)   printf("wrong password1\n");
			else if(flag_2 == -2)   printf("wrong password2\n");
			else
			{
				data[flag_1].cash += data[flag_2].cash;
				printf("success, %s has %lld dollars\n", id1, data[flag_1].cash);
				merge_rec(flag_1, flag_2);
				data[flag_2].cash = (long long int)-1;
			}
		}
		else if(strcmp(cmd, "deposit") == 0)
		{
			long long int num = 0; 
			scanf("%lld", &num);
			data[current_index].cash += num;
			printf("success, %lld dollars in current account\n", data[current_index].cash);
		}
		else if(strcmp(cmd, "withdraw") == 0)
		{
			long long int num = 0;
			scanf("%lld", &num);
			if(data[current_index].cash < num) printf("fail, %lld dollars only in current account\n", data[current_index].cash);
			else    {   data[current_index].cash -= num;   printf("success, %lld dollars left in current account\n", data[current_index].cash);   }
		}
		else if(strcmp(cmd, "transfer") == 0)
		{
			char id[MAX_LEN], psd[MAX_LEN] = "-";
			long long int num = 0;
			scanf("%s %lld", id, &num);
			int flag = check(id, psd);
			if(flag >= 0)
			{
				if(data[current_index].cash < num) printf("fail, %lld dollars only in current account\n", data[current_index].cash);
				else
				{
					data[flag].cash += num;
					data[current_index].cash -= num;
					printf("success, %lld dollars left in current account\n", data[current_index].cash);
					data[current_index].record.push_back(n_record);
					data[flag].record.push_back(n_record);
					strcpy(record[n_record].to, id);
					strcpy(record[n_record].from, data[current_index].account);
					record[n_record++].cash = num;
				}
			}
			else	{	printf("ID %s not found", id); find_10(id);	}
		}
		else if(strcmp(cmd, "search") == 0)
		{
			char id[MAX_LEN], psd[MAX_LEN] = "-";
			scanf("%s", id);
			int flag = check(id, psd);
			if(flag == -1)	printf("ID %s not found\n", id);
			else	find_rec(flag, id);
		}
	}
	return 0;
}

