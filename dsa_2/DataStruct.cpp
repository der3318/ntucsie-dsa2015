#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "DataStruct.h"

#define LINE_MAX 150000000
#define USER_MAX 100000000
#define AD_MAX 100000000
#define ANS_MAX 1000000

Data::Data()
{
	line = new Line[LINE_MAX];
	user = new User[USER_MAX];
	ad = new Ad[AD_MAX];
}

Data::~Data()
{
	delete [] line;
	delete [] user;
	delete [] ad;
}

User::User()
{
	line_start = 0;
	line_end = -1;
}

Ad::Ad()
{
	users.clear();
}

void Data::get(int& u, int& a, int& q, int& p, int& d)
{
	int click = 0, impression = 0;
	for(int i = user[u].line_start ; i <= user[u].line_end ; i++)
		if(line[i].ad == a && line[i].query == q && line[i].position == p && line[i].depth == d)
		{
			click += line[i].click;
			impression += line[i].impression;
		}
	printf("********************\n%d %d\n********************\n", click, impression);
	return;
}

void Data::clicked(int& u)
{
	int output[ANS_MAX][2] = {0}, n = 0, i = 0, j = 0;
	for(i = user[u].line_start ; i <= user[u].line_end ; i++)
	{
		if(line[i].click == 0)	continue;
		for(j = 0 ; j < n ; j++)	if(line[i].ad == output[j][0] && line[i].query == output[j][1])	break;
		if(j == n)
		{	
			output[n][0] = line[i].ad;
			output[n][1] = line[i].query;
			n++;
		}
	}
	qsort(output, n, sizeof(output[0]), cmp);
	printf("********************\n");
	for(int i = 0 ; i < n ; i++)	printf("%d %d\n", output[i][0], output[i][1]);
	printf("********************\n");
	return;
}

void Data::impressed(int& u, int& u_2)
{
	int output[ANS_MAX] = {0}, n = 0;
	for(int i = user[u].line_start ; i <= user[u].line_end ; i++)
	{
		for(int j = user[u_2].line_start ; j <= user[u_2].line_end ; j++)	
			if(line[i].ad == line[j].ad)	
			{
				output[n++] = line[i].ad;
				break;
			}
	}
	std::sort(output, output + n);
	printf("********************\n");
	for(int i = 0 ; i < n ; i++)
	{
		if(i > 0 && output[i] == output[i - 1])	continue;
		printf("%d\n", output[i]);
		std::vector<int> advertisers, keywords, titles, descriptions;
		std::vector<std::string> URLs;
		int size = 0;
		for(int j = user[u].line_start ; j >= 0 ; j++)
		{
			if(j == user[u].line_end + 1)	j = user[u_2].line_start;
			if(line[j].ad == output[i])
			{
				int k = 0;
				std::string tmp(line[j].URL);
				for(k = 0 ; k < size ; k++)
					if(line[j].keyword == keywords.at(k) && line[j].title == titles.at(k) && line[j].description == descriptions.at(k) && line[j].advertiser == advertisers.at(k) && tmp == URLs.at(k))	break;
				if(k == size)
				{
						printf("\t%s %d %d %d %d\n", line[j].URL, line[j].advertiser, line[j].keyword, line[j].title, line[j].description);
						URLs.push_back(tmp);
						advertisers.push_back(line[j].advertiser);
						keywords.push_back(line[j].keyword);
						titles.push_back(line[j].title);
						descriptions.push_back(line[j].description);
						size++;
				}
			}
			if(j == user[u_2].line_end)	break;
		}
	}
	printf("********************\n");
	return;
}

void Data::profit(int& a, double& rate)
{
	int output[ANS_MAX] = {0}, n = 0, size = ad[a].users.size();
	for(int i = 0 ; i < size ; i++)
	{
		int c_sum = 0, i_sum = 0;
		for(int j = user[ ad[a].users.at(i) ].line_start ; j <= user[ ad[a].users.at(i) ].line_end ; j++)
			if(line[j].ad == a)
			{
				c_sum += line[j].click;
				i_sum += line[j].impression;
			}
		if( i_sum != 0 && ((double)c_sum / (double)i_sum) >= (rate - 0.00001) )	output[n++] = ad[a].users.at(i);
	}
	std::sort(output, output + n);
	printf("********************\n");
	for(int i = 0 ; i < n ; i++)	printf("%d\n", output[i]);
	printf("********************\n");
	return;
}

int cmp(const void *a, const void *b)
{
	if( ((int*)a)[0] == ((int*)b)[0])	return	((int*)a)[1] - ((int*)b)[1];
	return ((int*)a)[0] - ((int*)b)[0];
}
