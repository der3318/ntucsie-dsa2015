#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "binomial_heap.h"

#define MAX 20

class Cmd
{
	public:
		int id;
		int p;
		Cmd(){}
		Cmd(int _id, int _p): id(_id), p(_p)	{}
		bool operator>(const Cmd& _cmd)
		{
			if(p > _cmd.p)	return true;
			if(p == _cmd.p && id < _cmd.id)	return true;
			return false;
		}
};

int main()
{
	int n_cm = 0, w = 0;
	char command[MAX];
	scanf("%d %d", &n_cm, &w);
	BinomialHeap<Cmd> *cms = new BinomialHeap<Cmd> [n_cm];
	while(scanf("%s", command) != EOF)
	{
		int cm = 0, cm_2 = 0;
		Cmd cmd;
		if(strcmp(command, "assign") == 0)	
		{
			scanf("%d %d %d", &cm, &cmd.id, &cmd.p);
			cms[cm].insert(cmd);
			printf("There are %d tasks on computer %d.\n", cms[cm].size, cm);
		}
		else if(strcmp(command, "execute") == 0)
		{
			scanf("%d", &cm);
			cmd = cms[cm].pop();
			printf("Computer %d executed task %d.\n", cm, cmd.id);
			while(cms[cm].size != 0 && cms[cm].peek().p == cmd.p)
			{
				cmd = cms[cm].pop();
				printf("Computer %d executed task %d.\n", cm, cmd.id);
			}
		}
		else if(strcmp(command, "merge") == 0)
		{
			scanf("%d %d", &cm, &cm_2);
			if(cms[cm_2].size >= w)
			{
				cms[cm].merge(cms[cm_2]);
				printf("The largest priority number is now %d on %d.\n", cms[cm].peek().p, cm);
			}
			else	printf("Merging request failed.\n");
		}
	}
	return 0;
}
