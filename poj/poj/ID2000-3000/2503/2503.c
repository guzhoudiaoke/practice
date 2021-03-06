/*
 * poj 2503
 * guzhoudiaoke@126.com
 * 2011-09-07
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD	979997

typedef struct dic_list {
	char english[11];
	char foreign[11];
	struct dic_list *next;
} dic_list;

dic_list dictionary[MOD];

void insert(char english[], char foreign[])
{
	int len = strlen(foreign);
	int i, key = 0;
	for (i = 0; i < len; i++)
		key += (foreign[i]-'a') << (2*(9-i));
	
	key %= MOD;
	dic_list *node = (dic_list *)malloc(sizeof(dic_list));
	strcpy(node->english, english);
	strcpy(node->foreign, foreign);
	dic_list *p = dictionary[key].next;
	dictionary[key].next = node;
	node->next = p;
}

void search(char word[], char translate[])
{
	int len = strlen(word);
	int i, key = 0;
	for (i = 0; i < len; i++)
		key += (word[i]-'a') << (2*(9-i));

	key %= MOD;
	dic_list *p = dictionary[key].next;
	while (p)
	{
		if (strcmp(word, p->foreign) == 0)
		{
			strcpy(translate, p->english);
			return;
		}
		p = p->next;
	}
	
	strcpy(translate, "eh\0");
}

int main()
{
	int i;
	char english[11];
	char foreign[11];
	char buf[25];
	for (i = 0; i < MOD; i++)
		dictionary[i].next = NULL;

	while (gets(buf) && strcmp(buf, ""))
	{
		sscanf(buf, "%s%s", english, foreign);
		insert(english, foreign);
	}

	char word[11];
	char translate[11];

	while (scanf("%s", word) != EOF)
	{
		search(word, translate);
		printf("%s\n", translate);
	}


	return 0;
}
