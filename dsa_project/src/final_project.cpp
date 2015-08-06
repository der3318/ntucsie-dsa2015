#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include "md5.h"
#include "wildcard.h"
extern "C"{
#include "rb.h"
}	
#define MAX_HASH 500000
#define MAX_LEN 110
#define MAX_REC 500000
#define MAX_DATA 500000
#define MAX_STR_INDEX 62

class Record 
{
	public:
		int cash;
		int to, from;
		Record(){}
		Record(int _cash, int _to, int _from):   cash(_cash), to(_to), from(_from) {}
};

class Data
{
	public:
		char account[MAX_LEN];
		MD5 password;
		int cash;
		std::vector<int> record;
		Data(){}
		Data(char *_id, MD5& _password, int _cash):  password(_password), cash(_cash)    {	strcpy(account, _id);	}
		~Data(){	record.clear();	}
};

class Index
{
	public:
		std::vector<int> index;
};

int cmp_data(const void *pa, const void *pb, void *param);

class IDs
{
	public:
		struct rb_table *index;
		IDs()	{	index = rb_create(cmp_data, NULL, NULL);	}
};

class Part
{
	public:
		int len;
		std::vector<int> pos;
};

Index *hash_table;
Data *data;
int n_record, n_data, current_index, tmp_index;
Record *record; 
IDs *ids;
std::vector<int> ids_len[100];
int char_to_int[130];

int cmp_data(const void *pa, const void *pb, void *param)
{
		const int* a = (const int*)pa;
		const int* b = (const int*)pb;
		if(strcmp(data[*a].account, data[*b].account) < 0)	return -1;
		else if(strcmp(data[*a].account, data[*b].account) > 0)	return +1;
		return 0;
}

void push_id(char *_id, int _index)
{
	int *element = (int*)malloc(sizeof(int));
	*element = _index;
	int index = char_to_int[(int)*_id];
	rb_probe(ids[index].index, element);
	ids_len[strlen(_id) - 1].push_back(_index);
}

int diff(char *id_1, char *id_2)
{
	int size = strlen(id_1), output = size - strlen(id_2);
	if(output > 0)	size -= output;
	else	output = -output;
	output = (output + 1) * output / 2;
	for(int i = size - 1 ; i >= 0 ; i--)	if(id_1[i] != id_2[i])	output += (size - i);
	return output;
}

void find_in_len(int &len_index, char *_id, std::pair<int, int> *output, int &n)
{
	for(std::vector<int>::iterator it = ids_len[len_index].begin() ; it != ids_len[len_index].end() ; it++)
	{
		int index = *it;
		if(data[index].cash != -1)
		{
			int d = diff(_id, data[index].account);
			if(n < 10 || d < output[9].first || (d == output[9].first && strcmp(data[index].account, data[ output[9].second ].account) < 0))
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
	}
}

void find_10(char *_id)
{
	std::pair<int, int> output[11];
	int index = (strlen(_id) - 1), n = 0, flag = 1, count = 1;
	find_in_len(index, _id, output, n);
	while(n < 10 || output[9].first >= flag)
	{
		int index_left = index - count, index_right = index + count;
		if(index_left <= -1 && index_right >= 100)	break;
		if(index_left > -1)	find_in_len(index_left, _id, output, n);
		if(index_right < 100)	find_in_len(index_right, _id, output, n);
		count++;	flag += count;
	}
	if(n > 0)	printf("%s", data[ output[0].second ].account);
	for(int i = 1 ; i < n ; i++)	printf(",%s", data[ output[i].second ].account);
	printf("\n");
}

void find_reg_in_rb(struct rb_node *node, char *_p, int &n)
{
	if(node == NULL)	return;
	find_reg_in_rb(node->rb_link[0], _p, n);
	int index = *((int*)(node->rb_data));
	if(data[index].cash != -1 && WildTextCompare(data[index].account, _p) && index != current_index)
	{
		if(n == 0)	printf("%s", data[index].account);
		else	printf(",%s", data[index].account);
		n++;
	}
	find_reg_in_rb(node->rb_link[1], _p, n);
}

void find(char* _p)
{
	int n = 0;
	if(*_p != '*' && *_p != '?')
	{
		int index = char_to_int[(int)*_p];
		find_reg_in_rb(ids[index].index->rb_root, _p, n);
	}
	else	for(int i = 0 ; i < 62 ; i++)	find_reg_in_rb(ids[i].index->rb_root, _p, n);
	printf("\n");
}

int hashingID(char *_id)
{
	int index = 0;
	while(*_id != '\0')	index = (index * 71 + char_to_int[(int)*_id++]) % MAX_HASH;
	return index;
}

int check(char *id, char* psd)
{
	int index = hashingID(id), size = hash_table[index].index.size(), i = 0;
	for(i = 0 ; i < size ; i++)	if( strcmp(data[ hash_table[index].index[i] ].account, id) == 0 )	break;
	if(i == size)	return -1;
	MD5 psd_md(psd);
	if(data[ hash_table[index].index[i] ].cash == -1)	{	tmp_index = hash_table[index].index[i];	return -3;	}
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
			if(record[ r_2[n_2] ].to == index_2)	record[ r_2[n_2] ].to = index_1;
			else	record[ r_2[n_2] ].from = index_1;
			new_record.push_back(r_2[n_2++]);
		}
		else
		{
			if(record[ r_1[n_1] ].to == index_1)	record[ r_1[n_1] ].from =  -1;
			else	record[ r_1[n_1] ].to = -1;
			new_record.push_back(r_1[n_1++]);
			n_2++;
		}
	}
	while(n_1 != size_1)	new_record.push_back(r_1[n_1++]);
	while(n_2 != size_2)
	{
		if(record[ r_2[n_2] ].to == index_2)	record[ r_2[n_2] ].to = index_1;
		else	record[ r_2[n_2] ].from = index_1;
		new_record.push_back(r_2[n_2++]);
	}
	r_1 = new_record;
}	

void find_rec(int &flag, char *id)
{
	std::vector<int> &r = data[current_index].record;
	int size = r.size(), n = 0, found = 0;
	if(flag == -3)	flag = tmp_index;
	if(flag == current_index)
		while(n < size)
		{
			if(record[ r[n] ].to == -1)	{	printf("To %s %d\nFrom %s %d\n", id, record[ r[n] ].cash, id, record[ r[n] ].cash);	found = 1;	}
			else if(record[ r[n] ].from == -1)	{	printf("From %s %d\nTo %s %d\n", id, record[ r[n] ].cash, id, record[ r[n] ].cash);	found = 1;	}
			n++;
		}
	else
		while(n < size)
		{
			if(record[ r[n] ].to == flag)	{	printf("To %s %d\n", id, record[ r[n] ].cash);	found = 1;	}
			else if(record[ r[n] ].from == flag)	{	printf("From %s %d\n", id, record[ r[n] ].cash);	found = 1;	}
			n++;
		}
	if(found == 0)	printf("no record\n");
}

void find_part(int d, std::vector<Part> &part, Part &p_try, int now)
{
	if(now == 0)	{	if(d == 0)	part.push_back(p_try);	return;	}
	if(d < 0 || d > now * (now + 1) / 2)	return;
	if(d >= now)
	{
		p_try.pos.push_back(now);
		find_part(d - now, part, p_try, now - 1);
		p_try.pos.pop_back();
	}
	find_part(d, part, p_try, now - 1);
}

void put_word(char *_id, char *id, std::vector<int> &pos, std::vector< std::string > &output, int &size, int now, int &found)
{
	if(now == (int)(pos.size()))
	{
		char psd[MAX_LEN] = "-";
		if(check(id, psd) < 0)	{	std::string s(id);	output.push_back(s);	found++;	}
		return;
	}
	char used = _id[ size - pos[now] ];
	for(char c = '0' ; c <= '9' && found < 10 ; c++)	if(c != used)	{	id[ size - pos[now] ] = c;	put_word(_id, id, pos, output, size, now + 1, found);	}
	for(char c = 'A' ; c <= 'Z' && found < 10 ; c++)	if(c != used)	{	id[ size - pos[now] ] = c;	put_word(_id, id, pos, output, size, now + 1, found);	}
	for(char c = 'a' ; c <= 'z' && found < 10 ; c++)	if(c != used)	{	id[ size - pos[now] ] = c;	put_word(_id, id, pos, output, size, now + 1, found);	}
}

void add_word(char *_id, char *id, Part &p, std::vector< std::string > &output, int &size, int now, int &found)
{
	if(now == p.len)	{	id[size + now] = '\0';	put_word(_id, id, p.pos, output, size, 0, found);	return;	}
	for(char c = '0' ; c <= '9' && found < 10 ; c++)	{	id[size + now] = c;	add_word(_id, id, p, output, size, now + 1, found);	}
	for(char c = 'A' ; c <= 'Z' && found < 10 ; c++)	{	id[size + now] = c;	add_word(_id, id, p, output, size, now + 1, found);	}
	for(char c = 'a' ; c <= 'z' && found < 10 ; c++)	{	id[size + now] = c;	add_word(_id, id, p, output, size, now + 1, found);	}
}

void find_diff(char *_id, int d, int &n)
{
	std::vector<Part> part;
	std::vector< std::string > output;
	Part p_try;
	p_try.len = 0;
	int size = strlen(_id);
	while(p_try.len * (p_try.len + 1) / 2 <= d)
	{
		find_part(d - p_try.len * (p_try.len + 1) / 2, part, p_try, d - p_try.len * (p_try.len +  1) / 2);
		(p_try.len)++;
	}
	for(int i = 0 ; i < (int)part.size() ; i++)
	{
		if(size - part[i].len > 0 && (part[i].pos.empty() || part[i].len + part[i].pos[0] <= size))
		{
			int found = 0, size_now = size - part[i].len;
			char new_id[MAX_LEN];
			strncpy(new_id, _id, size - part[i].len);
			new_id[size - part[i].len] = '\0';
			put_word(_id, new_id, part[i].pos, output, size_now, 0, found);
		}
		if(part[i].len != 0 && size + part[i].len <= 100 && (part[i].pos.empty() || part[i].pos[0] <= size))
		{
			int found = 0;
			char new_id[MAX_LEN];
			strcpy(new_id, _id);
			add_word(_id, new_id, part[i], output, size, 0, found);
		}
	}
	std::sort(output.begin(), output.end());
	for(std::vector< std::string >::iterator it = output.begin() ; n < 10 && it != output.end() ; n++)
	{
		if(n > 0)	printf(",");
		std::cout << (*it++);
	}
}

void find_10_free(char *_id)
{
	int d = 1, n = 0;
	while(n < 10)	find_diff(_id, d++, n);
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
	current_index = -1;
	for(char c = '0' ; c <= '9' ; c++)	char_to_int[(int)c] = (int)(c - '0');
	for(char c = 'A' ; c <= 'Z' ; c++)	char_to_int[(int)c] = (int)((c - 'A') + 10);
	for(char c = 'a' ; c <= 'z' ; c++)	char_to_int[(int)c] = (int)((c - 'a') + 36);
	char cmd[MAX_LEN], id[MAX_LEN], psd[MAX_LEN], id_2[MAX_LEN], psd_2[MAX_LEN], psd_for_check[MAX_LEN] = "-", pattern[MAX_LEN];
	while(scanf("%s", cmd) != EOF)
	{
		if(cmd[0] == 'l')
		{
			scanf("%s %s", id, psd);
			int flag = check(id, psd);
			if(flag == -1 || flag == -3)	printf("ID %s not found\n", id);
			else if(flag == -2) printf("wrong password\n");
			else	{	current_index = flag;	printf("success\n");	}
		}
		else if(cmd[0] == 'c')
		{
			scanf("%s %s", id, psd);
			int flag = check(id, psd);
			if(flag == -2 || flag >= 0)  {	printf("ID %s exists, ", id);	find_10_free(id);	}
			else
			{
				printf("success\n");
				MD5 psd_md(psd);
				Data new_data(id, psd_md, 0);
				if(flag == -3)	data[tmp_index] = new_data;
				else	{	data[n_data] = new_data;	hash_table[ hashingID(id) ].index.push_back(n_data);	push_id(id, n_data++);	}
			}
		}
		else if(cmd[0] == 'd' && cmd[2] == 'l')
		{
			scanf("%s %s", id, psd);
			int flag = check(id, psd);
			if(flag == -1 || flag == -3)  printf("ID %s not found\n", id);
			else if(flag == -2) printf("wrong password\n");
			else	{	data[flag].cash = -1;	printf("success\n");	}
		}
		else if(cmd[0] == 'm')
		{
			scanf("%s %s %s %s", id, psd, id_2, psd_2);
			int flag_1 = check(id, psd), flag_2 = check(id_2, psd_2);
			if(flag_1 == -1 || flag_1 == -3) printf("ID %s not found\n", id);
			else if(flag_2 == -1 || flag_2 == -3)    printf("ID %s not found\n", id_2);
			else if(flag_1 == -2)   printf("wrong password1\n");
			else if(flag_2 == -2)   printf("wrong password2\n");
			else
			{
				data[flag_1].cash += data[flag_2].cash;
				printf("success, %s has %d dollars\n", id, data[flag_1].cash);
				merge_rec(flag_1, flag_2);
				data[flag_2].cash = -1;
			}
		}
		else if(cmd[0] == 'd' && cmd[2] == 'p')
		{
			int num = 0; 
			scanf("%d", &num);
			data[current_index].cash += num;
			printf("success, %d dollars in current account\n", data[current_index].cash);
		}
		else if(cmd[0] == 'w')
		{
			int num = 0;
			scanf("%d", &num);
			if(data[current_index].cash < num) printf("fail, %d dollars only in current account\n", data[current_index].cash);
			else    {   data[current_index].cash -= num;   printf("success, %d dollars left in current account\n", data[current_index].cash);   }
		}
		else if(cmd[0] == 't')
		{
			int num = 0;
			scanf("%s %d", id, &num);
			int flag = check(id, psd_for_check);
			if(flag >= 0)
			{
				if(data[current_index].cash < num) printf("fail, %d dollars only in current account\n", data[current_index].cash);
				else
				{
					data[flag].cash += num;
					data[current_index].cash -= num;
					printf("success, %d dollars left in current account\n", data[current_index].cash);
					data[current_index].record.push_back(n_record);
					data[flag].record.push_back(n_record);
					record[n_record].to = flag;
					record[n_record].from = current_index;
					record[n_record++].cash = num;
				}
			}
			else	{	printf("ID %s not found, ", id); find_10(id);	}
		}
		else if(cmd[0] == 's')
		{
			scanf("%s", id);
			int flag = check(id, psd_for_check);
			find_rec(flag, id);
		}
		else if(cmd[0] == 'f')
		{
			scanf("%s", pattern);
			find(pattern);
		}
	}
	return 0;
}
