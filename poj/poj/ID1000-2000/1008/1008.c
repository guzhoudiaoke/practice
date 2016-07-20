/*
 * poj 1008
 * guzhoudiaoke
 * 2011-09-23
 */

#include <stdio.h>
#include <string.h>

typedef struct haab {
	int year;
	char month[10];
	int day;
} haab;

typedef struct tzolkin {
	int year;
	char period[10];
	int day;
} tzolkin;

char haa_month[18][10] = { "pop\0", "no\0", "zip\0", "zotz\0", "tzec\0", "xul\0", 
						  "yoxkin\0", "mol\0", "chen\0", "yax\0", "zac\0", "ceh\0", 
						  "mac\0", "kankin\0", "muan\0", "pax\0", "koyab\0", "cumhu\0" };

char tzo_month[20][10] = { "imix\0", "ik\0", "akbal\0", "kan\0", "chicchan\0", 
						  "cimi\0", "manik\0", "lamat\0", "muluk\0", "ok\0", 
						  "chuen\0", "eb\0", "ben\0", "ix\0", "mem\0", 
						  "cib\0", "caban\0", "eznab\0", "canac\0", "ahau\0" };

void haab_to_tzolkin(haab haa, tzolkin *tzo)
{
	int i, nday = haa.year*365;
	for (i = 0; i < 18; i++)
		if (strcmp(haa.month, haa_month[i]) == 0)
			break;

	nday += (i*20 + haa.day);

	tzo->year = nday / 260;
	tzo->day = (nday - 260*tzo->year) % 13 + 1;
	strcpy(tzo->period, tzo_month[(nday - 260*tzo->year) % 20]);
}

int main()
{
	int n, i;

	haab haa;
	tzolkin tzo;

	scanf("%d", &n);
	printf("%d\n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d. %s %d", &haa.day, haa.month, &haa.year);
		haab_to_tzolkin(haa, &tzo);
		printf("%d %s %d\n", tzo.day, tzo.period, tzo.year);
	}

	return 0;
}
