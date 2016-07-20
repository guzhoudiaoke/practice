/*
 * poj 2006
 * guzhoudiaoke@126.com
 * 2011-09-01
 */

#include <stdio.h>
#include <stdlib.h>

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
	
	int a, d, n;
	
	while (1)
	{
		scanf("%d%d%d", &a, &d, &n);
		if (a == 0 && d == 0 && n == 0)
			break;
		
		i = 0;
		if (is_prime[a])
			i = 1;
		while (i < n)
		{
			a += d;
				
			if (is_prime[a])
				i++;
		}
		printf("%d\n", a);
	}
	
	return 0;
}
