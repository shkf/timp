#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct node
{
	int data;
	struct node * left;
	struct node * right;
	struct node * rodit;
}
node;

typedef struct tree {
	struct node * Root;

	int count;
}
tree;

void init(tree* t)
{
	struct tree * new_tree = malloc(sizeof new_tree);
	new_tree->Root = NULL;
	new_tree->count = 0;
	t = new_tree;
}

int find(tree* t, int zna4, node* n)
{
	struct node * s2;
	s2 = t->Root;
	if (t->Root == NULL)
	{
		return 1;
	}

	while (1)
	{
		if (s2 == NULL)
		{
			return 1;
		}
		else if (s2->data == zna4)
		{
			n->data = s2->data;
			n->left = s2->left;
			n->right = s2->right;
			n->rodit = s2->rodit;
			return 0;
		}
		else if (zna4 > s2->data)
		{
			s2 = s2->right;
		}
		else
		{
			s2 = s2->left;
		}
	}
	return 1;
}

int insert(tree* t, int zna4)
{
	struct node * n, ** strrrr, *pr_str = NULL;
	struct node * e_n;
	e_n = malloc(sizeof * e_n);
	int error_tree = find(t, zna4, e_n);
	if (error_tree == 0)
	{
		return 1;
	}
	strrrr = &t->Root;
	n = t->Root;
	while (1)
	{
		if (n == NULL)
		{
			n = *strrrr = malloc(sizeof * n);
			if (n != NULL)
			{
				n->data = zna4;
				n->left = NULL;
				n->right = NULL;
				n->rodit = pr_str;
				t->count++;
				return 0;
			}
			else
			{
				return 2;
			}
		}

		pr_str = n;
		if (zna4 > n->data)
		{
			strrrr = &n->right;
			n = n->right;
		}
		else
		{
			strrrr = &n->left;
			n = n->left;
		}
	}
	return 0;
}

int depth(struct node * n, int deep)
{
	if (n == NULL)
	{
		return deep;
	}
	int depth1 = depth(n->left, deep + 1);
	int depth2 = depth(n->right, deep + 1);
	return (depth1 > depth2) ? depth1 : depth2;
}

void printNode(struct node * n, int current, int deep, int first)
{
	if (current == deep)
	{
		if (first > 0)
		{
			printf(" ");
		}
		if (n == NULL)
		{
			printf(" ");
		}
		else
		{
			printf("%d", n->data);
		}
	}
	else if (n != NULL)
	{
		printNode(n->left, current + 1, deep, first);
		printNode(n->right, current + 1, deep, first + 1);
	}
	else
	{
		printNode(n, current + 1, deep, first);
		printNode(n, current + 1, deep, first + 1);
	}
}

void print(struct node * n)
{

	int m = depth(n, 0);
	for (int i = 1; i <= m; i++)
	{
		printNode(n, 1, i, 0);
		printf("\n");
	}
}

void printTree(struct tree * t)
{
	print(t->Root);
}

void print_obh1(struct node * n)
{
	int m = depth(n, 0);
	int flag_tree = 0;
	for (int i = 1; i <= m; i++)
	{
		if (flag_tree > 0)
		{
			printf(" ");
		}
		else
		{
			flag_tree++;
		}
		printNode(n, 1, i, 0);
	}
}

int main()
{
	struct tree * t = malloc(sizeof t);
	init(t);
	for (int i = 0; i< 7; i++)
	{
		int a;
		scanf("%d", &a);
		insert(t, a);
	}
	print_obh1(t->Root);
	printf("\n");
	return 0;
}
