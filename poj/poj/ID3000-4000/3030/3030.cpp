/*
 * problem:	poj 1042
 * author:	guzhoudiaoke
 * time:	2011-10-04
 */

#include <stdio.h>

int main()
{
	int n, r, e, c;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d %d %d", &r, &e, &c);
		int t = r + c;
		if (t > e)
			printf("do not advertise\n");
		else if (t == e)
			printf("does not matter\n");
		else
			printf("advertise\n");
	}

	return 0;
}