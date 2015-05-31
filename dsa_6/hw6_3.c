#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl_ntudsa.h"
#define MAX 100000

int father[MAX], rank[MAX], f_s[MAX], s_f[MAX];
struct avl_table *tree[MAX];
long long int dollar, max_game;

void find_max_game(const struct avl_node *node)
{
	if(node == NULL)	return;
	if((long long int)(node->avl_sum[0]) <= dollar)
	{
		max_game += (node->avl_cnode[0]);
		dollar -= (node->avl_sum[0]);
		long long int tmp = dollar / (node->avl_data);
		if(tmp > (long long int)node->avl_cnt)	tmp = node->avl_cnt;
		max_game += tmp;
		dollar -= (tmp * (node->avl_data));
		if(tmp == node->avl_cnt)
		{
			if((long long int)(node->avl_sum[1]) <= dollar)
			{
				max_game += (node->avl_cnode[1]);
				dollar -= (node->avl_sum[1]);
			}
			else	find_max_game(node->avl_link[1]);
		}
	}
	else	find_max_game(node->avl_link[0]);
}

void merge_tree(struct avl_node *node, struct avl_table *new_tree)
{
	if(node == NULL)	return;
	if(node->avl_link[0] != NULL || node->avl_link[1] != NULL)
	{
		merge_tree(node->avl_link[0], new_tree);
		merge_tree(node->avl_link[1], new_tree);
	}
	for(int i = 0 ; i < node->avl_cnt ; i++)	avl_probe(new_tree, node->avl_data);
	free(node);
}

int get_father(int x)
{
	if(father[x] == x)	return x;
	return get_father(father[x]);
}

void merge_set(int fx, int fy, int o)
{
	if(rank[fx] > rank[fy])
	{
		father[fy] = fx;
		f_s[o] = fx;
		s_f[fx] = o;
		merge_tree(tree[fy]->avl_root, tree[fx]);
	}
	else
	{
		father[fx] = fy;
		f_s[o] = fy;
		s_f[fy] = o;
		merge_tree(tree[fx]->avl_root, tree[fy]);
		if(rank[fx] == rank[fy])	rank[fy]++;
	}
}

int int_compare(const void *pa, const void *pb, void *param)
{
	int a = *(const int*)pa;
	int b = *(const int*)pb;
	if(a < b)	return -1;
	else if(a > b)	return +1;
	else return 0;
}

int main()
{
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	memset(rank , 0, n);
	for(int i = 0 ; i < n ; i++)
	{
		int price = 0;
		scanf("%d", &price);
		tree[i] = avl_create(int_compare, NULL, NULL);
		avl_probe(tree[i], price);
		father[i] = i;
		f_s[i] = i;
		s_f[i] = i;
	}
	for(int i = 0 ; i < m ; i++)
	{
		int cmd = 0;
		scanf("%d", &cmd);
		if(cmd == 1)
		{
			int game_1 = 0, game_2 = 0;
			scanf("%d %d", &game_1, &game_2);
			int set_1 = get_father(game_1 - 1), set_2 = get_father(game_2 - 1);
			if(set_1 != set_2)	merge_set(set_2, set_1, s_f[set_1]);
		}
		else
		{
			int game = 0;
			scanf("%d %lld", &game, &dollar);
			max_game = 0;
			int set = get_father(game - 1);
			find_max_game(tree[set]->avl_root);
			printf("%d %lld\n", s_f[set] + 1, max_game);
		}
	}
	return 0;
}
