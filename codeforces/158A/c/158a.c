#include <stdio.h>

#define MAX	64

int main()
{
	int n, k, i;
	int scores[MAX];

	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &scores[i]);
	}

	for (i = 0; i < n; i++) {
		if (scores[i] <= 0 || scores[i] < scores[k-1])
			break;
	}
	printf("%d\n", i);

	return 0;
}
