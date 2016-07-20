/*
 * poj2739
 * guzhoudiaoke@126.com
 * 2011-08-28
 */

#include <stdio.h>

#define MAX_NUM		10000

int get_primes(int *primes)
{
	primes[0] = 2;
	int prime_num = 1;
	int i, j;
	
	for (i = 3; i < MAX_NUM; i++)
	{
		for (j = 0; j < prime_num; j++)
		{
			if (i % primes[j] == 0)
				break;
		}
		if (j == prime_num)
		{
			primes[prime_num] = i;
			prime_num++;
		}
	}
	
	return prime_num;
}
 
int main()
{
	int primes[MAX_NUM / 2];
	int prime_num = get_primes(primes);
	int i, j, num, n, temp;
	
	while (1)
	{
		n = 0;
		
		scanf("%d", &num);
		if (num == 0)
			break;
			
		for (i = 0; i < prime_num; i++)
		{
			temp = 0;
			for (j = i; j < prime_num; j++)
			{
				temp += primes[j];
				if (temp >= num)
					break;
			}
			if (temp == num)
				n++;
		}
		
		printf("%d\n", n);
	}
	
		
	return 0;
}
