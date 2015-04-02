#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "DataStruct.h"

#define MAX 150000000

int main(int argc,char *argv[])
{
	FILE *fin = fopen(argv[1], "r");
	if(NULL == fin)
	{
		printf("Fail to access the file.\n");
		return 1;
	}
	Data mydata;
	int i = 0;
	printf("Now reading data...\n");	//hint
	clock_t  clockBegin, clockEnd;	//time
	clockBegin = clock();	//time
	while(fscanf(fin, "%d%d%s%d%d%d%d%d%d%d%d%d", &mydata.line[i].click, &mydata.line[i].impression, mydata.line[i].URL, &mydata.line[i].ad, &mydata.line[i].advertiser, &mydata.line[i].depth, &mydata.line[i].position, &mydata.line[i].query, &mydata.line[i].keyword, &mydata.line[i].title, &mydata.line[i].description, &mydata.line[i].user) != EOF)
	{
		if(mydata.user[mydata.line[i].user].line_end == -1)
		{
			mydata.user[mydata.line[i].user].line_start = i;
			mydata.user[mydata.line[i].user].line_end = i;
			mydata.ad[mydata.line[i].ad].users.push_back(mydata.line[i].user);
		}
		else
		{
			(mydata.user[mydata.line[i].user].line_end)++;
			if(mydata.ad[mydata.line[i].ad].users.empty() || mydata.ad[mydata.line[i].ad].users.back() != mydata.line[i].user)
				mydata.ad[mydata.line[i].ad].users.push_back(mydata.line[i].user);
		}
		i++;
	}
	clockEnd = clock();	//time
	printf("Successfully completed in %ld sec(s)! Actions are now available.( get / clicked / impressed / profit / quit )\n\n", (clockEnd - clockBegin) / 1000000);	//hint
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
