#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include "DataStruct.h"

#define LINE_MAX 150000000
#define USER_MAX 30000000
#define AD_MAX 30000000
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
	{
		if(line[i].ad == a && line[i].query == q && line[i].position == p && line[i].depth == d)
		{
			click += line[i].click;
			impression += line[i].impression;
		}
	}
	printf("********************\n%d %d\n********************\n", click, impression);
	return;
}

void Data::clicked(int& u)
{
	printf("********************\n");
	int pre_ad = -1, pre_query = -1;
	for(int i = user[u].line_start ; i <= user[u].line_end ; i++)
		if(line[i].click != 0 && !(line[i].ad == pre_ad && line[i].query == pre_query))
		{
			printf("%d %d\n", line[i].ad, line[i].query);
			pre_ad = line[i].ad;
			pre_query = line[i].query;
		}
	printf("********************\n");
	return;
}

void Data::impressed(int& u, int& u_2)
{
	int output[ANS_MAX] = {0}, n = 0, i = user[u].line_start, j = user[u_2].line_start, u_tmp = user[u].line_start, u2_tmp = user[u_2].line_start;
	while (i <= user[u].line_end && j <= user[u_2].line_end){
		if(line[i].ad < line[j].ad)	i++;
		else if(line[i].ad > line[j].ad)	j++;
		else
		{
			output[n++] = line[i++].ad;
			j++;
		}
	}
	printf("********************\n");
	for(i = 0 ; i < n ; i++)
	{
		if(i > 0 && output[i] == output[i - 1])	continue;
		printf("%d\n", output[i]);
		find_properties(output[i], u, u_2, u_tmp, u2_tmp);
	}
	printf("********************\n");
	return;
}

void Data::profit(int& a, double& rate)
{
	int size = ad[a].users.size();
	printf("********************\n");
	for(int i = 0 ; i < size ; i++)
	{
		double c_sum = 0, i_sum = 0;
		for(int j = user[ ad[a].users.at(i) ].line_start ; j <= user[ ad[a].users.at(i) ].line_end ; j++)
			if(line[j].ad == a)
			{
				c_sum += line[j].click;
				i_sum += line[j].impression;
			}
		if(c_sum / i_sum >= (rate - 0.000001))	printf("%d\n", ad[a].users.at(i));
	}
	printf("********************\n");
	return;
}

int cmp_line(const void *a, const void *b)
{
	if( ((Line*)a)->ad == ((Line*)b)->ad )	return ((Line*)a)->query - ((Line*)b)->query;
	return ((Line*)a)->ad - ((Line*)b)->ad;
}

void Data::find_properties(int& ad_target, int& u, int& u_2, int& u_tmp, int& u2_tmp)
{
	std::vector<int> advertisers, keywords, titles, descriptions;
	std::vector<unsigned long long> URLs;
	int size = 0;
	for(int j = u_tmp ; j <= user[u].line_end  ; j++)
	{
		if(line[j].ad == ad_target)
		{
			int k = 0;
			for(k = 0 ; k < size ; k++)
				if(line[j].keyword == keywords.at(k) && line[j].title == titles.at(k) && line[j].description == descriptions.at(k) && line[j].advertiser == advertisers.at(k) && line[j].URL == URLs.at(k))	break;
			if(k == size)
			{
				printf("\t%llu %d %d %d %d\n", line[j].URL, line[j].advertiser, line[j].keyword, line[j].title, line[j].description);
				URLs.push_back(line[j].URL);
				advertisers.push_back(line[j].advertiser);
				keywords.push_back(line[j].keyword);
				titles.push_back(line[j].title);
				descriptions.push_back(line[j].description);
				size++;
			}
		}
		else if(line[j].ad > ad_target)
		{
			u_tmp = j;
			break;
		}
	}
	for(int j = u2_tmp ; j <= user[u_2].line_end  ; j++)
	{
		if(line[j].ad == ad_target)
		{
			int k = 0;
			for(k = 0 ; k < size ; k++)
				if(line[j].keyword == keywords.at(k) && line[j].title == titles.at(k) && line[j].description == descriptions.at(k) && line[j].advertiser == advertisers.at(k) && line[j].URL == URLs.at(k))	break;
			if(k == size)
			{
				printf("\t%llu %d %d %d %d\n", line[j].URL, line[j].advertiser, line[j].keyword, line[j].title, line[j].description);
				URLs.push_back(line[j].URL);
				advertisers.push_back(line[j].advertiser);
				keywords.push_back(line[j].keyword);
				titles.push_back(line[j].title);
				descriptions.push_back(line[j].description);
				size++;
			}
		}
		else if(line[j].ad > ad_target)
		{
			u2_tmp = j;
			break;
		}
	}
	return;
}
