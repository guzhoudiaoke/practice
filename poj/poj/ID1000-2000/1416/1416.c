/*
 * poj 1416
 * guzhoudiaoke@126.com
 * 2011-09-11
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int target, number, max;
char str[8];
int rejected;

typedef struct link_list {
	int num;
	struct link_list *next;
} link_list;

link_list *list;
link_list *result;

int create_list(link_list **l)
{
	(*l) = (link_list *)malloc(sizeof(link_list));
	if (*l == NULL) return 0;

	(*l)->next = NULL;
	return 1;
}

// 在node后面插入data
int insert_list(link_list *node, int data)
{
	link_list *p = node->next;
	link_list *new_node = (link_list *)malloc(sizeof(link_list));
	if (new_node == NULL) return 0;

	new_node->num = data;
	node->next = new_node;
	new_node->next = p;

	return 1;
}

void clear_list(link_list *l)
{
	link_list *p = l->next;
	link_list *q;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
}


int free_list(link_list **l)
{
	clear_list(*l);
	free(*l);
}


void init_list(link_list *l, char *str)
{
	int len = strlen(str);
	int i;
	link_list *p = l;
	for (i = 0; i < len; i++)
	{
		insert_list(p, str[i]-'0');
		p = p->next;
	}
}

void copy_list(link_list *from, link_list **to)
{
	clear_list(*to);
	link_list *p = from->next;
	link_list *q = *to;
	while (p)
	{
		link_list *node = (link_list *)malloc(sizeof(link_list));
		node->num = p->num; node->next = NULL;
		q->next = node;
		q = q->next;
		p = p->next;
	}
}

void dfs(link_list *node, int sum)
{
	if (node == NULL)
		return;

	if (sum == max)
		rejected = 1;
	else if (sum > max && sum <= target)
	{
		rejected = 0;
		max = sum;
		copy_list(list, &result);
	}
	else if (sum > target)
		return;

	link_list *q, *r;
	r = node;
	while (r->next)
	{
		int temp = sum + r->num*9;
		r->num = r->num*10 + r->next->num;
		q = r->next;
		r->next = q->next;
		free(q);
		dfs(r, temp);
		int x = r->num % 10;
		r->num /= 10;
		q = (link_list *)malloc(sizeof(link_list));
		q->num = x;
		q->next = r->next;
		r->next = q;

		r = r->next;
	}
}

int main()
{
	int i;
	while (1)
	{
		create_list(&list);
		create_list(&result);

		scanf("%d%s", &target, str);
		if (target == 0 && strcmp(str, "0") == 0)
			break;

		init_list(list, str);
		
		int sum = 0;
		link_list *p = list->next;
		while (p)
		{
			sum += p->num;
			p = p->next;
		}

		max = 0;
		rejected = 0;
		p = list->next;

		dfs(p, sum);

		if (rejected)
			printf("rejected\n");
		else if (max == 0)
			printf("error\n");
		else
		{
			printf("%d", max);
			p = result->next;
			while (p)
			{
				printf(" %d", p->num);
				p = p->next;
			}
			printf("\n");
		}
		
		free_list(&list);
		free_list(&result);
	}

	return 0;
}

