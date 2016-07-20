/* poj2159
 *  思路：
 *  若第一行经过变幻后各个字母个数与第二行相等则可以得到结果
 *  否则得不到
 *  guzhoudiaoke@126.com
 *  2011-08-27
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpint(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int src_num[26];
	int dst_num[26];
	char ch;
	int i;
	
	// 初始化为0，表示A～Z个数都为0
	for (i = 0; i < 26; i++)
	{
		src_num[i] = 0;
		dst_num[i] = 0;
	}
	
	// 统计个数
	while ((ch=getchar()) != '\n')
		src_num[ch - 'A'] ++;
	
	while ((ch=getchar()) != '\n')
		dst_num[ch - 'A'] ++;
		
	qsort(src_num, 26, sizeof(int), cmpint);
	qsort(dst_num, 26, sizeof(int), cmpint);
	
	
	for (i = 0; i < 26; i++)
	{
		if (dst_num[i] != src_num[i])
		{
			printf("NO");
			return 0;
		}
	}
	
	printf("YES");
	
	return 0;
}
