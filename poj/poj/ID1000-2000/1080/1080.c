/*
 * poj 1080
 * guzhoudiaoke@126.com
 * 2011-09-14
 */

#include <stdio.h>

#define MAX	1000000

int score[256][256];

void set_score(int score[256][256])
{
	score['A']['A'] =  5; score['A']['C'] = -1; score['A']['G'] = -2; score['A']['T'] = -1; score['A']['-'] = -3;
	score['C']['A'] = -1; score['C']['C'] =  5; score['C']['G'] = -3; score['C']['T'] = -2; score['C']['-'] = -4;
	score['G']['A'] = -2; score['G']['C'] = -3; score['G']['G'] =  5; score['G']['T'] = -2; score['G']['-'] = -2;
	score['T']['A'] = -1; score['T']['C'] = -2; score['T']['G'] = -2; score['T']['T'] =  5; score['T']['-'] = -1;
	score['-']['A'] = -3; score['-']['C'] = -4; score['-']['G'] = -2; score['-']['T'] = -1; score['-']['-'] = -MAX;
}

int max(int a, int b, int c)
{
	int re = a;
	if (b > a) re = b;
	if (c > re) re = c;

	return re;
}

int solve(int len1, char *gene1, int len2, char *gene2)
{
	int dp[201][201], i, j;
	
	dp[0][0] = 0;
	for (i = 1; i <= len2; i++)
		dp[0][i] = dp[0][i-1] + score['-'][gene2[i-1]];
	for (i = 1; i <= len1; i++)
		dp[i][0] = dp[i-1][0] + score[gene1[i-1]]['-'];
	for (i = 1; i <= len1; i++)
		for (j = 1; j <= len2; j++)
		{
			dp[i][j] = dp[i-1][j-1] + score[gene1[i-1]][gene2[j-1]];
			if (dp[i][j] < dp[i][j-1] + score['-'][gene2[j-1]])
				dp[i][j] = dp[i][j-1] + score['-'][gene2[j-1]];
			if (dp[i][j] < dp[i-1][j] + score[gene1[i-1]]['-'])
				dp[i][j] = dp[i-1][j] + score[gene1[i-1]]['-'];
		}
	
	return dp[len1][len2];
}

int main()
{
	int t, len1, len2;
	char gene1[101], gene2[101];

	set_score(score);
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d%s%d%s", &len1, gene1, &len2, gene2);
		printf("%d\n", solve(len1, gene1, len2, gene2));
	}

	return 0;
}
