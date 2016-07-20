/*
 * problem: poj 2326
 * author:	guzhoudiaoke
 * time:	2011-09-27
 */

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int major_scale[12][12];
int possible[12];
int addend[7] = { 2, 4, 5, 7, 9, 11, 12 };

char notes[12][4] = { 
	"C\0", "C#\0", "D\0", "D#\0", "E\0", "F\0", 
	"F#\0", "G\0", "G#\0", "A\0", "A#\0", "B\0" 
};

void init_major_scale()
{
	int i, j;
	memset(major_scale, 0, sizeof(major_scale));

	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < 7; j++)
			major_scale[i][(i+addend[j]) % 12] = 1;
	}
}

int translate_to_num(char note[])
{
	int i;
	for (i = 0; i < 12; i++)
		if (strcmp(note, notes[i]) == 0)
			break;
	return i;
}

int main()
{
	init_major_scale();
	char buf[2010], note[4], *p;
	int i, j;

	while (1)
	{
		for (i = 0; i < 12; i++)
			possible[i] = 1;
		cin.getline(buf, 2010);
		
		if (strcmp(buf, "END") == 0) break;
		
		p = buf;
		j = 0;
		while (1)
		{
			if (*p == ' ' || *p == '\0')
			{
				note[j] = '\0';
				int index = translate_to_num(note);
				for (i = 0; i < 12; i++)
					if (major_scale[i][index] == 0)
						possible[i] = 0;
				j = 0;
				if (*p == '\0')
					break;
			}
			else
			{
				note[j] = *p;
				j++;
			}
			p++;
		}

		for (i = 0; i < 12; i++)
		{
			if (possible[i])
				cout << notes[i] << " ";
		}
		cout << endl;
	}

	return 0;
}