/*
 * poj 2586
 * guzhoudiaoke@126.com
 * 2011-09-03
 */

#include <stdio.h>

int main()
{
	int s, d, ans;
	
	while (scanf("%d %d", &s, &d) == 2)
	{
		if (4*s - d < 0) 	ans =10*s - 2*d;	// ssssd ssssd ss
		else if (3*s - 2*d < 0) ans = 8*s - 4*d;	// sssdd sssdd ss
		else if (2*s - 3*d < 0) ans = 6*s - 6*d;	// ssddd ssddd ss
		else if (s - 4*d < 0)   ans = 3*s - 9*d;	// sdddd sdddd sd
		else			ans = -1;
		
		if (ans < 0)
			printf("Deficit\n");
		else
			printf("%d\n", ans);
	}
	
	return 0;
}

