/*
 * poj 2247
 * guzhoudiaoke@126.com
 * 2011-11-14 20:04
 */

#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

long long humble[5843];

long long min_4(long long f2, long long f3, long long f5, long long f7)
{
	long long ret = f2;
	if (ret > f3) ret = f3;
	if (ret > f5) ret = f5;
	if (ret > f7) ret = f7;

	return ret;
}

void get_humble()
{
	humble[1] = 1;
	int f2 = 1, f3 = 1, f5 = 1, f7 = 1;
	int index = 2;

	while (index <= 5842) {
		humble[index] = min_4(humble[f2]*2, humble[f3]*3, humble[f5]*5, humble[f7]*7);
	
		if (humble[index] == humble[f2]*2) f2++;
		if (humble[index] == humble[f3]*3) f3++;
		if (humble[index] == humble[f5]*5) f5++;
		if (humble[index] == humble[f7]*7) f7++;
		
		index++;
	}
}

void get_str(string &str, int n)
{
	if (n%10 == 1 && n%100 != 11) str = "st";
	else if (n%10 == 2 && n%100 != 12) str = "nd";
	else if (n%10 == 3 && n%100 != 13) str = "rd";
	else str = "th";
}

int main()
{
	int n;
	string str;

	get_humble();
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		get_str(str, n);

		printf("The %d%s humble number is %lld.\n", n, str.c_str(), humble[n]);
	}

	return 0;
}
