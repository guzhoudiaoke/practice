/* poj 1001
 * 孤舟钓客
 * 2011-07-19
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define LEN 6
#define RESULT_LEN 150

// 将字符串转换成逆置的数组表示的格式，返回小数位数
int covert(char str[LEN], unsigned int cov[LEN - 1])
{
	int temp[LEN - 1];
	memset(temp, 0, sizeof(temp));

	// 赋值
	int i = 0, j = 0;
	while (i < LEN && str[i])
	{
		if (str[i] != '.')
			temp[j++] = str[i] - '0';
		i++;
	}
	
	// 逆置
	for (i = 0; i < LEN-1; i++)
		cov[i] = temp[LEN - 2 - i];

	// 返回小数位数
	int pos = 0;				// 小数点位置
	while (str[pos] && str[pos] != '.')
		pos++;

	return LEN - pos - 1;
}

// 大数乘法，result = R * result
void multiplication(unsigned int R[LEN-1], unsigned int result[RESULT_LEN])
{
	unsigned int temp[RESULT_LEN];
	memset(temp, 0, sizeof(temp));

	int i, j;
	for (i = 0; i < LEN-1; i++)
		for (j = 0; j < RESULT_LEN-LEN; j++)
			temp[i + j] += R[i] * result[j];

	// 处理乘积大于10 的地方
	int carry = 0;				// 表示进位
	for (i = 0; i < RESULT_LEN; i++)
	{
		result[i] = (carry + temp[i]) % 10;
		carry = (carry + temp[i]) / 10;
	}
}

// 大数指数运算，R 的n 次方
void exponent(unsigned int R[LEN - 1], int n, unsigned int result[RESULT_LEN])
{
	int i;
	if (n == 0)
	{
		memset(result, 0, sizeof(unsigned int) * RESULT_LEN);
		result[0] = 1;
		return;
	}
	for (i = 1; i < n; i++)
	{
		multiplication(R, result);
	}
}

// 按要求输出，result 为要输出的数据，num 为R 的小数位数，用于计算result 的小数位数
void display(int num, int n, unsigned int result[RESULT_LEN])
{
	// result 中数据是逆置的，前面为小数部分，后面为整数部分
	// 小数点位置通过R 中小数位数及指数n 来确定
	
	// 例如1.2300 的2 次方，结果为1.5129，则num = 4, n = 2
	// result = 0000921510000...0

	// 后面的0
	int back = RESULT_LEN - 1;
	while (result[back] == 0 && back != 0)
		back--;
	
	// 前面的0
	int pre = 0;
	while (result[pre] == 0 && pre < RESULT_LEN)
		pre++;

	// 由于result 是逆置的，故输出时要反过来

	// 输出整数部分
	int i;
	for (i = back; i >= n*num; i--)
		printf("%d", result[i]);

	// 输出小数点
	if (num && n*num >= pre+1)
		printf(".");
	
	// 输出小数部分
	for (i = n*num-1; i >= pre; i-- )
		printf("%d", result[i]);
}

int main()
{
	int n;						// 指数 n
	char str_r[LEN + 1];				// R 的字符串表示
	unsigned int R[LEN - 1];			// 将R 表示成int 型数组
	unsigned int result[RESULT_LEN];		// 结果

	while ((scanf("%s%d", str_r, &n)) == 2)
	{
		memset(R, 0, sizeof(unsigned int) * (LEN - 1));
		memset(result, 0, sizeof(unsigned int) * RESULT_LEN);

		int num = covert(str_r, R);		// 小数位数 num
		covert(str_r, result);
		exponent(R, n, result);			// 指数运算
		display(num, n, result);		// 按要求输出数据

		memset(str_r, 0, sizeof(char) * (LEN+1));
		printf("\n");
	}

	return 0;
}

