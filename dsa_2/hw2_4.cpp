#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "DataStruct.h"

#define MAX 150000000
#define USER_MAX 30000000
#define AD_MAX 30000000

int main(int argc,char *argv[])
{
	FILE *fin = fopen(argv[1], "r");
	if(NULL == fin)
	{
		printf("Fail to access the file.\n");
		return 1;
	}
	Data mydata;
	int i = 0, user = 0;
	printf("Now reading data...\n");	//hint
	clock_t  clockBegin, clockEnd;	//time
	clockBegin = clock();	//time
	while(fscanf(fin, "%d%d%s%d%d%d%d%d%d%d%d%d", &mydata.line[i].click, &mydata.line[i].impression, mydata.line[i].URL, &mydata.line[i].ad, &mydata.line[i].advertiser, &mydata.line[i].depth, &mydata.line[i].position, &mydata.line[i].query, &mydata.line[i].keyword, &mydata.line[i].title, &mydata.line[i].description, &user) != EOF)
	{
		if(mydata.user[user].line_end == -1)
		{
			mydata.user[user].line_start = i;
			mydata.user[user].line_end = i;
			mydata.ad[mydata.line[i].ad].users.push_back(user);
		}
		else
		{
			(mydata.user[user].line_end)++;
			if(mydata.ad[mydata.line[i].ad].users.empty() || mydata.ad[mydata.line[i].ad].users.back() != user)
				mydata.ad[mydata.line[i].ad].users.push_back(user);
		}
		i++;
	}
	clockEnd = clock();	//time
	printf("Data 100%% loaded! Process successfully completed in %ld sec(s)!\nNow sorting data...\n", (clockEnd - clockBegin) / 1000000);	//hint
	clockBegin = clock();	//time
	for(i = 0 ; i < USER_MAX ; i++)	if(mydata.user[i].line_end != -1)	qsort(&mydata.line[ mydata.user[i].line_start ], mydata.user[i].line_end - mydata.user[i].line_start + 1, sizeof(mydata.line[0]), cmp_line);	
	for(i = 0 ; i < AD_MAX ; i++)	std::sort(mydata.ad[i].users.begin(), mydata.ad[i].users.end());
	clockEnd = clock();	//time
	printf("Data 100%% sorted! Process successfully completed in %ld sec(s)!\nActions are now available.( get / clicked / impressed / profit / quit )\n\n", (clockEnd - clockBegin) / 1000000);	//hint
	char command[20];
	int u = 0, a = 0, q = 0, p = 0, d = 0, u_2 = 0;
	double theta = 0;
	while(1)
	{
		scanf("%s", command);
		clockBegin = clock();	//time
		if(strcmp(command, "quit") == 0)	break;
		else if(strcmp(command, "get") == 0)
		{
			scanf("%d %d %d %d %d", &u, &a, &q, &p, &d);
			mydata.get(u, a, q, p, d);
		}
		else if(strcmp(command, "clicked") == 0)
		{
			scanf("%d", &u);
			mydata.clicked(u);
		}
		else if(strcmp(command, "impressed") == 0)
		{
			scanf("%d %d", &u, &u_2);
			mydata.impressed(u, u_2);
		}
		else if(strcmp(command, "profit") == 0)
		{
			scanf("%d %lf", &a, &theta);
			mydata.profit(a, theta);
		}
		clockEnd = clock();	//time
		printf("Action \"%s\" takes %ld ms.\n\n", command, (clockEnd - clockBegin) / 1000);	//time
	}
	return 0;
}
