/*
 * poj 1326
 * guzhoudiaoke@126.com
 * 2011-09-20
 */

#include <stdio.h>
#include <string.h>

int main()
{
	int summary = 0, miles;
	char buf[200], ori_city[100], dist_city[100], type[20];

	while (1)
	{
		gets(buf);
		if (strcmp(buf, "#") == 0)
			break;
		else if (strcmp(buf, "0") == 0)
		{
			printf("%d\n", summary);
			summary = 0;
		}
		else
		{
			sscanf(buf, "%s%s%d%s", ori_city, dist_city, &miles, type);
	
			if (strcmp(type, "F") == 0)
				summary += 2*miles;

			else if (strcmp(type, "B") == 0)
				summary += (miles + (miles+1)/2);
			
			else if (strcmp(type, "Y") == 0)
			{
				if (miles <= 500)
					summary += 500;
				else
					summary += miles;
			}
		}
	}

	return 0;
}

