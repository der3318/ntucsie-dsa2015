#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX_DATA 10000
#define MAX_LEN 1000000

class Case
{
	public:
		int yn;
		double *data;
};

std::vector<Case> cases;
int max_index = 0;
int index_tmp = 0;

bool cmp(int a, int b){	return cases[a].data[index_tmp] < cases[b].data[index_tmp];	}
double confusion(int a, int b){	return 1 - pow((double)a / (a + b), 2) - pow((double)b / (a + b), 2);	}

void print_decision(std::vector<int> toCheck, int now)
{
	int y = 0, index_hold = -1, size = toCheck.size();
	double min = 1, value_hold = 0;
	for(int i = 0 ; i < size ; i++)	if(cases[ toCheck[i] ].yn == 1)	y++;
	for(index_tmp = 1 ; index_tmp <= max_index ; index_tmp++)
	{
		std::sort(toCheck.begin(), toCheck.end(), cmp);
		int y_tmp = (cases[ toCheck[0] ].yn == 1 ? 1 : 0);
		for(int i = 1 ; i < size ; i++)
		{
			if(fabs(cases[ toCheck[i] ].data[index_tmp] - cases[ toCheck[i - 1] ].data[index_tmp]) > 0.000001)
			{	
				double conf_tmp = (confusion(y_tmp, (i - y_tmp)) * i  + confusion((y - y_tmp), (size - i - y + y_tmp)) * (size - i)) / (double)size;
				if(conf_tmp < min)
				{
					min = conf_tmp;
					index_hold = index_tmp;
					value_hold = (cases[ toCheck[i] ].data[index_tmp] + cases[ toCheck[i - 1] ].data[index_tmp]) / 2.0;
				}
			}
			if(cases[ toCheck[i] ].yn == 1)	y_tmp++;
		}
	}
	if(confusion(y, size - y) <= 0.000001 || index_hold == -1)
	{
		for(int i = 0 ; i < now ; i++)	printf("\t");
		if(y > size - y)	printf("t++;\n");
		else	printf("f++;\n");
		return;
	}
	std::vector<int> toCheck_1, toCheck_2;
	for(int i = 0 ; i < size ; i++)
	{
		if(cases[ toCheck[i] ].data[index_hold] < value_hold)	toCheck_1.push_back(toCheck[i]);
		else	toCheck_2.push_back(toCheck[i]);
	}
	for(int i = 0 ; i < now ; i++)	printf("\t");	printf("if(attr[%d] < %lf){\n", index_hold, value_hold);
	print_decision(toCheck_1, now + 1);
	for(int i = 0 ; i < now ; i++)	printf("\t");	printf("}\n");
	for(int i = 0 ; i < now ; i++)	printf("\t");	printf("else{\n");
	print_decision(toCheck_2, now + 1);
	for(int i = 0 ; i < now ; i++)	printf("\t");	printf("}\n");
	return;
}

int main(int argc, char *argv[])
{
	FILE *fin = fopen(argv[1], "r");
	if(NULL == fin)	printf("Fali to access the file.\n");
	int n = 0, index = 0;
	std::vector<int> toCheck;
	char c_tmp[MAX_LEN];
	while(fgets(c_tmp, MAX_LEN, fin) != 0)
	{
		Case case_new;
		case_new.data = new double[MAX_DATA];
		for(int i = 0 ; i < MAX_DATA ; i++)	case_new.data[i] = 0;
		if(c_tmp[0] == '\n')	continue;
		c_tmp[ strlen(c_tmp) - 1 ] = '\0';		
		char *cut = strtok(c_tmp, " ");
		case_new.yn = atoi(cut);
		cut = strtok(NULL, ":");
		while(cut != NULL)
		{
			index = atoi(cut);
			cut = strtok(NULL, " ");
			case_new.data[index] = atof(cut);
			cut = strtok(NULL, ":");
		}
		if(index > max_index)	max_index = index;
		cases.push_back(case_new);
		toCheck.push_back(n++);
	}
	fclose(fin);
	printf("int forest_predict(double *attr){\n\tint t = 0, f = 0;\n");
	srand( (unsigned)time(NULL) );
	for(int i = 1 ; i <= atoi(argv[2]) ; i++)
	{
		printf("tree%d_predict:\n", i);
		int base[MAX_DATA];
		std::vector<int> toCheck;
		for(int j = 0 ; j < n ; j++)	base[j] = j;
		for(int j = 0 ; j < n / 3 ; j++)
		{
			int k = j + rand() % (n - j);
			std::swap(base[j], base[k]);
			toCheck.push_back(base[j]);
		}
		print_decision(toCheck, 1);
	}
	printf("voting:\n\tif(t > f)\treturn 1;\n\telse\treturn -1;\n}\n");
	return 0;
}
