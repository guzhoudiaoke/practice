/*
 * problem:	poj 1037
 * author:	guzhoudiaoke
 * time:	2011-10-10
 */

#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

long long dpm[21][21];
long long dpw[21][21];
/* dpw[i][j] 表示共i 根棍，其中第一根长位j，且下降的数目 
 * dpm[i][j] 表示共i 根棍，其中第一根长位j，且上升的数目 */

vector<int> left;

void solve(int n)
{
	int i, j, k;

	memset(dpw, 0, sizeof(dpw));
	memset(dpm, 0, sizeof(dpm));

	dpm[1][1] = 1; dpw[1][1] = 1;

	for (i = 2; i <= n; i++)
		for (j = 1; j <= i; j++)
		{
			for (k = j; k <= i-1; k++)
				dpm[i][j] += dpw[i-1][k];
			for (k = 1; k <= j-1; k++)
				dpw[i][j] += dpm[i-1][k];
		}
}
 
/*
 * type = -1; 表示尚未确定类型
 * type =  0; 表示下一次递归类型为w
 * type =  1; 表示下一次类型为m
 */
void disp_ans(int n, long long c, int type, int start)
{
	int i;
	long long num  = 0;

	if (n == 1) {
		printf("%d\n", left[1]);
		return;
	}
	
	if (type == -1) {
		for (i = 1; i <= n; i++) {
			num += dpw[n][i];
			if (num >= c) {
				type = 1;
				num -= dpw[n][i];
				break;
			}
			
			num += dpm[n][i];
			if (num >= c) {
				type = 0;
				num -= dpm[n][i];
				break;
			}
		}
	}else if (type == 0) {
		type = 1;
		for (i = start; i <= n; i++) {
			num += dpw[n][i];
			if (num >= c) {
				num -= dpw[n][i];
				break;
			}
		}
	}else {
		type = 0;
		for (i = 1; i <= start; i++) {
			num += dpm[n][i];
			if (num >= c) {
				num -= dpm[n][i];
				break;
			}
		}
	}

	printf("%d ", left[i]);
	left.erase(left.begin()+i);
	
	disp_ans(n-1, c-num, type, i);
}

int main()
{
	int k, n;
	long long c;

	scanf("%d", &k);
	while (k--)
	{
		scanf("%d %lld", &n, &c);
		solve(n);

		left.clear();
		for (int i = 0; i <= n; i++)
			left.push_back(i);
		disp_ans(n, c, -1, 0);
	}

	return 0;
}