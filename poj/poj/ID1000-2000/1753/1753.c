/*
 * poj 1753
 * guzhoudiaoke@126.com
 * 2011-09-02
 */

#include <stdio.h>

int flip[16] = {
	0xC800, 0xE400, 0x7200, 0x3100,
	0x8C80, 0x4E40,	0x2720, 0x1310,
	0x08c8, 0x04E4, 0x0272, 0x0131,
	0x008c, 0x004E, 0x0027, 0x0013
};

int add[16] = {
	0x8000, 0x4000, 0x2000, 0x1000,
	0x0800, 0x0400, 0x0200, 0x0100,
	0x0080, 0x0040, 0x0020, 0x0010,
	0x0008, 0x0004, 0x0002, 0x0001
};

int times = 16;

// chessboard 表示当前局面，pos 为翻转位置，times 为翻转次数
void search(int chessboard, int pos, int flip_times)
{
	if (chessboard == 0 || chessboard == 0xffff)
	{
		if (flip_times < times)
			times = flip_times;
	}
	if (pos == 16)
		return;
 
 	search(chessboard, pos+1, flip_times);
 	search(chessboard ^= flip[pos], pos+1, flip_times+1);
}

int main()
{
	char ch;
	int i;
	int chessboard = 0;
	
	i = 0;
	while (i < 16)
	{
		scanf("%c", &ch);
		if (ch == '\n')
			continue;
		if (ch == 'b')
			chessboard += add[i];
		i++;
	}
	
	search(chessboard, 0, 0);
	
	if (times == 16)
		printf("Impossible\n");
	else
		printf("%d\n", times);
	
	return 0;
}
