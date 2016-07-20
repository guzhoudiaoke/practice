/*
 * poj 3087
 * guzhoudiaoke@126.com
 * 2011-09-10
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trie_tree {
	int apear;
	struct trie_tree *next[9];
} trie_tree;

trie_tree *root;

void trie_create(trie_tree **r)
{
	(*r) = (trie_tree *)malloc(sizeof(trie_tree));
	int i;
	for (i = 0; i < 9; i++)
		(*r)->next[i] = NULL;
	(*r)->apear = 0;
}

void trie_insert(char *str)
{
	trie_tree *p = root;
	while (*str)
	{
		if (p->next[*str - 'A'] == NULL)
		{
			trie_tree *node;
			trie_create(&node);
			p->next[*str - 'A'] = node;
		}
		p = p->next[*str - 'A'];
		str++;
	}
	
	p->apear = 1;
}

int trie_search(char *str)
{
	trie_tree *p = root;
	while (*str && p)
	{
		p = p->next[*str - 'A'];
		str++;
	}
	return (p && p->apear);
}

void trie_destroy(trie_tree **r)
{
	int i;
	for (i = 0; i < 9; i++)
		if ((*r)->next[i])
			trie_destroy(&((*r)->next[i]));
	
	free (*r);
}

int main()
{
	int n, c, i, j, times;
	char *s1, *s2, *s12, *desired;
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		trie_create(&root);
		scanf("%d", &c);
		s1 = (char *)malloc(sizeof(char) * (c+1));
		s2 = (char *)malloc(sizeof(char) * (c+1));
		s12 = (char *)malloc(sizeof(char) * (2*c+1));
		desired = (char *)malloc(sizeof(char) * (2*c+1));
		
		scanf("%s%s%s", s1, s2, desired);

		times = 0;
		while (1)
		{
			times ++;
			for (j = 0; j < c; j++)
			{
				s12[j*2] = s2[j];
				s12[j*2+1] = s1[j];
			}
			s12[2*c] = '\0';

			if (strcmp(s12, desired) == 0)
			{
				printf("%d %d\n", i, times);
				break;
			}
			if (trie_search(s12) == 1)
			{
				printf("%d -1\n", i);
				break;
			}
			else
			{
				trie_insert(s12);
				for (j = 0; j < c; j++)
				{
					s1[j] = s12[j];
					s2[j] = s12[c+j];
				}
				s1[c] = '\0';
				s2[c] = '\0';
			}
		}

		free(s1);
		free(s2);
		free(s12);
		free(desired);

		trie_destroy(&root);
	}

	return 0;
}
