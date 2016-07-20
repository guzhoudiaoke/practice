/*
 * poj 2996
 * guzhoudiaoke@126.com
 * 2011-09-04
 */

#include <stdio.h>

#define ROW	17
#define COLUMN	33

typedef struct piece {
	int no;
	int row;
	int col;
} piece;

int cmp_white(const void *a, const void *b)
{
	piece *piece_a = (piece *)a;
	piece *piece_b = (piece *)b;
	
	if (piece_a->no != piece_b->no)
		return piece_a->no - piece_b->no;
	else
	{
		if (piece_a->row != piece_b->row)
			return piece_a->row - piece_b->row;
		else
			return piece_a->col - piece_b->col;
	}
}

int cmp_black(const void *a, const void *b)
{
	piece *piece_a = (piece *)a;
	piece *piece_b = (piece *)b;
	
	if (piece_a->no != piece_b->no)
		return piece_a->no - piece_b->no;
	else
	{
		if (piece_a->row != piece_b->row)
			return piece_b->row - piece_a->row;
		else
			return piece_a->col - piece_b->col;
	}
}

int main()
{
	char map[ROW][COLUMN+1];
	piece whites[16];
	piece blacks[16];
	int piece_no[26];
	char piece_char[6];
	
	piece_no['K' - 'A'] = 1;
	piece_no['Q' - 'A'] = 2;
	piece_no['R' - 'A'] = 3;
	piece_no['B' - 'A'] = 4;
	piece_no['N' - 'A'] = 5;
	piece_no['P' - 'A'] = 6;
	
	piece_char[1] = 'K';
	piece_char[2] = 'Q';
	piece_char[3] = 'R';
	piece_char[4] = 'B';
	piece_char[5] = 'N';
	
	int i, j;
	
	for (i = 0; i < 16; i++)
	{
		whites[i].no = 0;
		blacks[i].no = 0;
	}
	
	for (i = 0; i < ROW; i++)
		scanf("%s", map[i]);
	
	int w, b;
	w = 0;
	b = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLUMN; j++)
		{
			if (map[i][j] > 'A' && map[i][j] < 'Z')		// 白棋
			{
				whites[w].no = piece_no[map[i][j]-'A'];
				whites[w].row = 9 - (i+1) / 2;
				whites[w].col = (j+2) / 4;
				w++;
			}
			else if (map[i][j] > 'a' && map[i][j] < 'z')	// 黑棋
			{
				blacks[b].no = piece_no[map[i][j]-'a'];
				blacks[b].row = 9 - (i+1) / 2;
				blacks[b].col = (j+2) / 4;
				b++;
			}
		}
	}
	
	qsort(whites, w, sizeof(piece), cmp_white);
	printf("White: ");
	for (i = 0; i < w; i++)
	{
		if (whites[i].no == 6)
			printf("%c%d", whites[i].col-1+'a', whites[i].row);
		else
			printf("%c%c%d", piece_char[whites[i].no], whites[i].col-1+'a', whites[i].row);
		if (i != w-1)
			printf(",");
	}
	printf("\n");
	
	qsort(blacks, b, sizeof(piece), cmp_black);
	printf("Black: ");
	for (i = 0; i < b; i++)
	{
		if (blacks[i].no == 6)
			printf("%c%d", blacks[i].col-1+'a', blacks[i].row);
		else
			printf("%c%c%d", piece_char[blacks[i].no], blacks[i].col-1+'a', blacks[i].row);
		if (i != w-1)
			printf(",");
	}

	return 0;
}
