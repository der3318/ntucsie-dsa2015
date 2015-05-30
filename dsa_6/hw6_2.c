#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"
#include "bst.h"
#include "rb.h"
#define MAX_LEN 130

void preorder_string_avl(const struct avl_node *node)
{
	if(node == NULL)
		return;
	printf("%s ", ((char*)node->avl_data));
	if(node->avl_link[0] != NULL || node->avl_link[1] != NULL)
	{
		putchar('(');
		preorder_string_avl(node->avl_link[0]);
		putchar(',');
		putchar(' ');
		preorder_string_avl(node->avl_link[1]);
		putchar(')');
	}
}

void preorder_string_bst(const struct bst_node *node)
{
	if(node == NULL)
		return;
	printf("%s ", ((char*)node->bst_data));
	if(node->bst_link[0] != NULL || node->bst_link[1] != NULL)
	{
		putchar('(');
		preorder_string_bst(node->bst_link[0]);
		putchar(',');
		putchar(' ');
		preorder_string_bst(node->bst_link[1]);
		putchar(')');
	}
}

void preorder_string_rb(const struct rb_node *node)
{
	if(node == NULL)
		return;
	printf("%s ", ((char*)node->rb_data));
	if(node->rb_link[0] != NULL || node->rb_link[1] != NULL)
	{
		putchar('(');
		preorder_string_rb(node->rb_link[0]);
		putchar(',');
		putchar(' ');
		preorder_string_rb(node->rb_link[1]);
		putchar(')');
	}
}

int string_compare(const void *pa, const void *pb, void *param)
{
	const char* a = (const char*)pa;
	const char* b = (const char*)pb;
	if(strcmp(a, b) < 0)	return -1;
	else if(strcmp(a, b) > 0)	return +1;
	else return 0;
}

int main()
{
	struct avl_table *tree;
	struct bst_table *tree_2;
	struct rb_table *tree_3;
	tree = avl_create(string_compare, NULL, NULL);
	tree_2 = bst_create(string_compare, NULL, NULL);
	tree_3 = rb_create(string_compare, NULL, NULL);
	int i = 0;
	for(i = 0 ; i < 32 ; i++)
	{
		char *element = (char*)malloc(sizeof(char) * MAX_LEN);
		char *element_2 = (char*)malloc(sizeof(char) * MAX_LEN);
		char *element_3 = (char*)malloc(sizeof(char) * MAX_LEN);
		scanf("%s", element);
		strcpy(element_2, element);
		strcpy(element_3, element);
		avl_probe(tree, element);
		bst_probe(tree_2, element_2);
		rb_probe(tree_3, element_3);
	}
	preorder_string_avl(tree->avl_root);
	puts("");
	preorder_string_bst(tree_2->bst_root);
	puts("");
	preorder_string_rb(tree_3->rb_root);
	puts("");
	return 0;
}
