/*
 * poj 1316
 * guzhoudiaoke@126.com
 * 2011-11-23 20:28
 */

#include <stdio.h>
#include <string.h>

int main()
{
	int i, j, k, l;
	bool self_num[10100];
	memset(self_num, true, sizeof(self_num));

	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			for (k = 0; k < 10; k++)
				for (l = 0; l < 10; l++)
					self_num[i*1001 + j*101 + k*11 + l*2] = false;


	for (i = 0; i < 10001; i++)
		if (self_num[i])
			printf("%d\n", i);
	return 0;
}
