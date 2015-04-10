#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <omp.h>
#include "MapRead.h"

#define MAX 150000000
#define USER_MAX 30000000
#define AD_MAX 30000000

int main(int argc,char *argv[])
{
	Data mydata;
	printf("Now reading data...\n");	//hint
	clock_t  clockBegin, clockEnd;	//time
	clockBegin = clock();	//time
	int line = map_read(argv[1], mydata), i = 0;
	if(line == -1)	return 1;
	while(i != line)
	{
		if(mydata.user[ mydata.line[i].user ].line_end == -1)
		{
			mydata.user[ mydata.line[i].user ].line_start = i;
			mydata.user[ mydata.line[i].user ].line_end = i;
			mydata.ad[mydata.line[i].ad].users.push_back(mydata.line[i].user);
		}
		else
		{
			(mydata.user[ mydata.line[i].user ].line_end)++;
			if(mydata.ad[mydata.line[i].ad].users.empty() || mydata.ad[mydata.line[i].ad].users.back() != mydata.line[i].user)
				mydata.ad[mydata.line[i].ad].users.push_back(mydata.line[i].user);
		}
		i++;
	}
	clockEnd = clock();	//time
	printf("Data 100%% loaded! Process successfully completed in %ld sec(s)!\nNow sorting data...\n", (clockEnd - clockBegin) / 1000000);	//hint
	clockBegin = clock();	//time
	#pragma parallel for
	for(i = 0 ; i < USER_MAX ; i++)	if(mydata.user[i].line_end != -1)
		qsort(&mydata.line[ mydata.user[i].line_start ], mydata.user[i].line_end - mydata.user[i].line_start + 1, sizeof(mydata.line[0]), cmp_line);	
	for(i = 0 ; i < AD_MAX ; i++)
		std::sort(mydata.ad[i].users.begin(), mydata.ad[i].users.end());
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
