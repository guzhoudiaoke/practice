/*
 * poj 2262
 * guzhoudiaoke@126.com
 * 2011-09-01
 */

#include <stdio.h>

#define MAX		1000000
#define SQRT_MAX	1000

typedef enum BOOL {
	FALSE = 0, TRUE = !FALSE
} BOOL;

int main()
{
	// 筛法求素数
	BOOL is_prime[MAX+1];
	int i, j;
	
	memset(is_prime, TRUE, sizeof(is_prime));
	is_prime[0] = FALSE;
	is_prime[1] = FALSE;
	
	for (i = 2; i <= SQRT_MAX; i++)
	{
		if (is_prime[i])
		{
			for (j = i+i; j <= MAX; j+=i)
				is_prime[j] = FALSE;
		}
	}
	
	int n;
	
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		int i;
		for (i = 3; i < MAX/2; i+=2)
		{
			if (is_prime[i] && is_prime[n-i])
			{
				printf("%d = %d + %d\n", n, i, n-i);
				break;
			}
		}
	}
	
	return 0;
}
