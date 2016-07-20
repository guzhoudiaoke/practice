/*
 * poj 2255
 * guzhoudiaoke@126.com
 * 2011-09-02
 */

#include <stdio.h>
#include <string.h>

void get_post(int len, char *pre, char *in, char *post)
{
	int i;
	if (len == 0)
		return;

	for (i = 0; i < len; i++)
		if (in[i] == pre[0])
			break;

	get_post(i, pre+1, in, post);
	get_post(len-i-1, pre+i+1, in+i+1, post+i);

	post[len-1] = pre[0];
	post[len] = '\0';
}

int main()
{
	char pre[27];
	char in[27];
	char post[27];
	
	while (scanf("%s%s", pre, in) != EOF)
	{
		get_post(strlen(pre), pre, in, post);
		printf("%s\n", post);
	}

	return 0;
}
