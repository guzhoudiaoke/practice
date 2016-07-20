/*
 * problem:	poj	1200
 * author:	guzhoudiaoke
 * time:	2011-10-15
 */

#include <stdio.h>
#include <string.h>

char text[1000000];
bool hash[16000000];
int n, nc, num[128];

int main()
{
	int i, j, h, w, ans = 0;
	scanf("%d %d", &n, &nc);
	scanf("%s", text);

	memset(hash, false, sizeof(hash));
	memset(num, 0, sizeof(num));

	i = 0;
	j = 0;
	while (1)
	{
		if (num[text[i]] == 0)
			num[text[i]] = j++;
		if (j == nc)
			break;
		i++;
	}

	char *pbeg, *pend, *q;
	pbeg = text;
	pend = text + n - 1;

	while (*pend)
	{
		q = pbeg;
		h = 0;
		w = 1;
		while (q <= pend)
		{
			h += w*num[*q];
			w *= nc;
			q++;
		}

		if (hash[h] == false)
		{
			hash[h] = true;
			ans ++;
		}
		pbeg++;
		pend++;
	}

	printf("%d\n", ans);

	return 0;
}
