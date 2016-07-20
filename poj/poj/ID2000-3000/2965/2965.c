/*
 * poj 2965
 * guzhoudiaoke@126.com
 * 2011-09-02
 */

#include <stdio.h>

int flip[16] = {
	0xF888, 0xF444, 0xF222, 0xF111,
	0x8F88, 0x4F44,	0x2F22, 0x1F11,
	0x88F8, 0x44F4, 0x22F2, 0x11F1,
	0x888F, 0x444F, 0x222F, 0x111F
};

int add[16] = {
	0x8000, 0x4000, 0x2000, 0x1000,
	0x0800, 0x0400, 0x0200, 0x0100,
	0x0080, 0x0040, 0x0020, 0x0010,
	0x0008, 0x0004, 0x0002, 0x0001
};

int min_times = 16;
int flip_pos[16];
int min_pos[16];

// chessboard 表示当前局面，pos 为翻转位置，times 为翻转次数
void search(int chessboard, int pos, int times)
{
	if (chessboard == 0)
	{
		if (times < min_times)
			min_times = times;
		int i;
		for (i = 0; i < min_times; i++)
			min_pos[i] = flip_pos[i];
	
	}
	
	if (pos == 16)
		return;
	
	
	flip_pos[times] = pos;
	search(chessboard ^ flip[pos], pos+1, times+1);
	
	flip_pos[times] = pos+1;
 	search(chessboard, pos+1, times);
 	
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
		if (ch != '+' && ch != '-')
			continue;
		if (ch == '+')
			chessboard += add[i];
		i++;
	}
	
	search(chessboard, 0, 0);

	printf("%d\n", min_times);
	for (i = 0; i < min_times; i++)
		printf("%d %d\n", min_pos[i]/4 + 1, min_pos[i]%4 + 1);
	
	return 0;
}
