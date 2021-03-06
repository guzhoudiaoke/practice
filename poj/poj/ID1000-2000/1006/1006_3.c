/*
 * poj1006 运用了中国剩余定理去解
 * guzhoudiaoke@126.com
 * 2011-08-30
 */

#include <stdio.h>

int main()
{
    	int p, e, i, d, max, n = 1;
    	
    	while (scanf("%d%d%d%d", &p, &e, &i, &d) == 4 && (p != -1 || e != -1 || i != -1 || d != -1))
    	{
    		// 28 * 33 = 924;	924 / 23 = 40...4;	4 * 6 / 23 = 1...1;	924 * 6 = 5544;
    		// 23 * 33 = 759;	759 / 28 = 27...3;	3 * 19 / 28 = 2...1;	759 * 19 = 14421;
    		// 23 * 28 = 644;	644 / 33 = 19...17;	17 * 2 / 33 = 1...1;	644 * 2 = 1288;
    		
       		max = (5544*p + 14421*e + 1288*i - d) % 21252;		// 为保证前面的数MOD后面的数大于等于1.因此要加上21252
       		if (max <= 0)
           		max += 21252;
        	printf("Case %d: the next triple peak occurs in %d days.\n", n++, max);
    	}
    	
    	return 0;
}

