/*
 * poj 1035
 * guzhoudiaoke@126.com
 * 2011-09-04
 */

#include <stdio.h>
#include <string.h>

#define MAX_NUM	10000
#define MAX_LEN	15

typedef struct dictionary {
	char word[MAX_LEN+1];
	int len;
	int no;
} dictionary;

int cmp_dic_len(const void *a, const void *b)
{
	return ((dictionary *)a)->len - ((dictionary *)b)->len;
}

int cmp_dic_no(const void *a, const void *b)
{
	return ((dictionary *)a)->no - ((dictionary *)b)->no;
}

int main()
{
	dictionary dic[MAX_NUM+1];
	
	int dic_num = 0;
	while (1)
	{
		scanf("%s", dic[dic_num].word);
		if (strcmp(dic[dic_num].word, "#") == 0)
			break;
		dic[dic_num].len = strlen(dic[dic_num].word);
		dic[dic_num].no = dic_num;
		dic_num++;
	}
	
	int i;
	qsort(dic, dic_num, sizeof(dictionary), cmp_dic_len);
	int len_index[MAX_LEN+1];
	for (i = 0; i < MAX_LEN+1; i++)
		len_index[i] = -1;
	
	int max_len = dic[0].len;
	len_index[dic[0].len] = 0;
	
	for (i = 0; i < dic_num; i++)
		if (dic[i].len > dic[i-1].len )
			len_index[dic[i].len] = i;
	
	char test[MAX_LEN+1];	
	while (1)
	{
		scanf("%s", test);
		if (strcmp(test, "#") == 0)
			break;
		
		int len = strlen(test);
		int start, end;
		
		start = len_index[len];	// 字典中长度相同者的开始位置
		if (len == dic[dic_num-1].len)
			end = dic_num;	// 字典中长度相同者的结束位置
		else
		{
			for (i = len+1; i <= dic[dic_num-1].len; i++)
				if (len_index[i] > 0)
				{
					end = len_index[i]-1;
					break;
				}
		}
		
		dictionary rep[MAX_NUM+1];
		for (i = 0; i < MAX_NUM+1; i++)
			rep[i].no = MAX_NUM+1;
		int rep_num = 0;
		int correct = 0;
		if (start >= 0)			// 与字典中长度相同的单词比较
		{
			for (i = start; i <= end; i++)
			{
				if (strcmp(test, dic[i].word) == 0)
				{
					correct = 1;
					break;
				}
			}
		}
		
		/*************************************************************************/
		start = len_index[len-1];	// 比待查单词短一个字符的单词的开始位置
		if (len-1 == dic[dic_num-1].len)
			end = dic_num;		// 字典中长度短一相同者的结束位置
		else
		{
			for (i = len; i <= dic[dic_num-1].len; i++)
				if (len_index[i] > 0)
				{
					end = len_index[i]-1;
					break;
				}
		}
		if (start >= 0 && correct == 0)	// 与相同长度减一的单词比较
		{
			for (i = start; i <= end; i++)
			{
				int j;
				for (j = 0; j < len-1; j++)	
					if (test[j] != dic[i].word[j])
						break;
				if (strcmp(test+j+1, dic[i].word+j) == 0)
				{
					//printf(" %s", dic[i].word);
					rep[rep_num].no = dic[i].no;
					strcpy(rep[rep_num].word, dic[i].word);
					rep_num++;
				}
			}
		}
		
		/*************************************************************************/
		start = len_index[len];	// 字典中长度相同者的开始位置
		if (len == dic[dic_num-1].len)
			end = dic_num;	// 字典中长度相同者的结束位置
		else
		{
			for (i = len+1; i <= dic[dic_num-1].len; i++)
				if (len_index[i] > 0)
				{
					end = len_index[i]-1;
					break;
				}
		}
		if (start >= 0 && correct == 0)	// 与相同长度的单词比较看有几个字符不同
		{
			for (i = start; i <= end; i++)
			{
				int dif_ch = 0;
				int j;
				for (j = 0; j < len; j++)	
					if (test[j] != dic[i].word[j])
					{
						dif_ch++;
						if (dif_ch == 2)
							break;
					}
				if (dif_ch == 1)
				{
					//printf(" %s", dic[i].word);
					rep[rep_num].no = dic[i].no;
					strcpy(rep[rep_num].word, dic[i].word);
					rep_num++;
				}
			}
		}
		
		/*************************************************************************/
		start = len_index[len+1];	// 比待查单词长一个字符的单词的开始位置
		if (len+1 > MAX_LEN)
			start = -1;
		if (len+1 == dic[dic_num-1].len)
			end = dic_num;		// 字典中长度长一者的结束位置
		else
		{
			for (i = len+2; i <= dic[dic_num-1].len; i++)
				if (len_index[i] > 0)
				{
					end = len_index[i]-1;
					break;
				}
		}
		
		if (start >= 0 && correct == 0)	// 与相同长度减一的单词比较
		{
			for (i = start; i <= end; i++)
			{
				int j;
				for (j = 0; j < len; j++)	
					if (test[j] != dic[i].word[j])
						break;
				if (strcmp(test+j, dic[i].word+j+1) == 0)
				{
					//printf(" %s", dic[i].word);
					rep[rep_num].no = dic[i].no;
					strcpy(rep[rep_num].word, dic[i].word);
					rep_num++;
				}
			}
		}
		
		if (correct == 1)
			printf("%s is correct", test);
		else
		{
			printf("%s:", test);
			qsort(rep, rep_num, sizeof(dictionary), cmp_dic_no);
			for (i = 0; i < rep_num; i++)
				printf(" %s", rep[i].word);
		}
		printf("\n");
	}
	
	return 0;
}
