/*
 * poj 1094
 * guzhoudiaoke@126.com
 * 2011-09-18
 */

#include <stdio.h>
#include <string.h>

#define CYCLE			0
#define TOO_MANY_INDEGREE_0	1
#define SORTED			2
#define UNSORTED		3

int n, m;
int relation[26][26];
int indegree[26];
int char_apear[26];
int topological_sequence[26];

int topological_sort()
{
	int i, pos, count, cur_index, num_indegree_0, temp[26], failed, num_appear = 0;
	
	for (i = 0; i < n; i++)
		temp[i] = indegree[i];
	for (i = 0; i < n; i++)
		if (char_apear[i])
			num_appear++;
	
	count = 0;
	failed = 0;
	while (1)
	{
		num_indegree_0 = 0;
		for (i = 0; i < n; i++)
			if (temp[i] == 0 && char_apear[i])
				num_indegree_0++;
		
		if (num_indegree_0 == 0)	// 出现环
		{
			if (count != num_appear)
				return CYCLE;
			return UNSORTED;
		}
		else if (num_indegree_0 > 1)	// 入度为0 顶点多于一个
		{
			for (pos = 0; pos < n; pos++)
				if (temp[pos] == 0 && char_apear[pos])
				{
					for (i = 0; i < n; i++)
						if (relation[pos][i])
							temp[i]--;
					temp[pos] = -1;
					count++;
					failed = 1;
				}
		}
		else
		{
			for (pos = 0; pos < n; pos++)
				if (temp[pos] == 0 && char_apear[pos])
					break;
		
			topological_sequence[count++] = pos;
		
			for (i = 0; i < n; i++)
				if (relation[pos][i])
					temp[i]--;
		
			temp[pos] = -1;
			if (count == num_appear)
			{
				if (num_appear == n && !failed)
					return SORTED;
				return UNSORTED;
			}
		}
	}
	
	return UNSORTED;
}

int main()
{
	int i, cycle, num_indegree_0, result, sorted, determined;
	char ch_first, ch_operate, ch_second;
	while (1)
	{
		scanf("%d%d", &n, &m);
		getchar();
		if (n == 0 && m == 0)
			break;
		
		cycle = 0;
		sorted = 0;
		determined = 0;
		memset(indegree, 0, sizeof(indegree));
		memset(relation, 0, sizeof(relation));
		memset(char_apear, 0, sizeof(char_apear));

		for (i = 0; i < m; i++)
		{
			scanf("%c%c%c", &ch_first, &ch_operate, &ch_second);
			getchar();

			if (cycle || sorted)
				continue;
				
			indegree[ch_second-'A']++;
			char_apear[ch_first-'A'] = 1;
			char_apear[ch_second-'A'] = 1;
			relation[ch_first-'A'][ch_second-'A'] = 1;
			
			result = topological_sort();
			if (result == CYCLE)
				cycle = 1+i;
			else if (result == SORTED)
				sorted = 1+i;
		}

		if (cycle)
			printf("Inconsistency found after %d relations.\n", cycle);
		else if (sorted)
		{
			printf("Sorted sequence determined after %d relations: ", sorted);
			for (i = 0; i < n; i++)
				printf("%c", 'A' + topological_sequence[i]);
			printf(".\n");
		}
		else
			printf("Sorted sequence cannot be determined.\n");
	}

	return 0;
}

