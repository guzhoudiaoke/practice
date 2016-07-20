/*
 * poj 1298
 * guzhoudiaoke@126.com
 * 2011-08-31
 */

#include <stdio.h>
#include <string.h>

char map[26] = {
	'V','W','X','Y','Z','A','B','C','D','E','F','G','H',
	'I','J','K','L','M','N','O','P','Q','R','S','T','U'
};

int main()
{
	char message[501];
	
	while (1)
	{
		int i;
		
		gets(message);
			
		if (strcmp(message, "START") == 0 || strcmp(message, "END") == 0)
			continue;
		else if (strcmp(message, "ENDOFINPUT") == 0)
			break;
		else
		{
			
			for (i = 0; i < strlen(message); i++)
			{
				if (message[i] >= 'A' && message[i] <= 'Z')
					message[i] = map[message[i]-'A'];
				printf("%c", message[i]);
			}
			printf("\n");
		}
	}
	
	return 0;
}
