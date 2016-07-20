/*
 * poj 2538
 * guzhoudiaoke@126.com
 * 2011-11-26
 */

#include <stdio.h>
#include <string.h>

char code[128];

void set_code()
{
	code[';'] = 'L';
	code['L'] = 'K';
	code['K'] = 'J';
	code['J'] = 'H';
	code['H'] = 'G';
	code['G'] = 'F';
	code['F'] = 'D';
	code['D'] = 'S';
	code['S'] = 'A';
	code[','] = 'M';
	code['M'] = 'N';
	code['N'] = 'B';
	code['B'] = 'V';
	code['V'] = 'C';
	code['C'] = 'X';
	code['X'] = 'Z';
	code['['] = 'P';
	code['P'] = 'O';
	code['O'] = 'I';
	code['I'] = 'U';
	code['U'] = 'Y';
	code['Y'] = 'T';
	code['T'] = 'R';
	code['R'] = 'E';
	code['E'] = 'W';
        code['W'] = 'Q';
	code['/'] = '.';
	code['\''] = ';';
        code[']'] = '[';
	code['\\'] = ']';
	code['.'] = ',';
        code['='] = '-';
	code['-'] = '0';
	code['0'] = '9';
	code['9'] = '8';
	code['8'] = '7';
	code['7'] = '6';
	code['6'] = '5';
	code['5'] = '4';
	code['4'] = '3';
        code['3'] = '2';
	code['2'] = '1';
	code['1'] = '`';
	code[' ']=' ';
}

int main()
{
	char buf[100];
	set_code();

	while (gets(buf))
	{
		for (int i = 0; i < strlen(buf); i++)
			printf("%c", code[buf[i]]);
		printf("\n");
	}

	return 0;
}
