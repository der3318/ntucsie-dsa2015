#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void preorder_integer_avl(const struct avl_node *node)
{
	if(node == NULL)
		return;
	printf("%d ", *((int*)node->avl_data));
	if(node->avl_link[0] != NULL || node->avl_link[1] != NULL)
	{
		putchar('(');
		preorder_integer_avl(node->avl_link[0]);
		putchar(',');
		putchar(' ');
		preorder_integer_avl(node->avl_link[1]);
		putchar(')');
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
	struct avl_table *tree;
	tree = avl_create(int_compare, NULL, NULL);
	int i = 0;
	for(i = 0 ; i < 16 ; i++)
	{
		int *element = (int*)malloc(sizeof(int));
		*element = i;
		void **p = avl_probe(tree, element);
	}
	preorder_integer_avl(tree->avl_root);
	puts("");
	return 0;
}
