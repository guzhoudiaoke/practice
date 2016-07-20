/*
 * poj 1007
 * guzhoudiaoke@126.com
 * 2011-08-30
 */
 
#include <stdio.h>
#include <stdlib.h>

typedef struct dna_seq {
	char *dna;
	int inver;
} dna_seq;

int cmp_dna(const void *a, const void *b)
{
	return (*(dna_seq *)a).inver - (*(dna_seq *)b).inver;
}

int main()
{
	dna_seq *dna_array;
	int num, len, i, j, k;
	
	scanf("%d%d", &len, &num);
	dna_array = (dna_seq *)malloc(sizeof(dna_seq) * num);
	if (!dna_array)	return;
	for (i = 0; i < num; i++)
	{
		dna_array[i].dna = (char *)malloc(sizeof(char) * (len+1));
		if (!dna_array[i].dna)	return;
		
		scanf("%s", dna_array[i].dna);
		dna_array[i].inver = 0;
		
		for (j = 0; j < len-1; j++)
		{
			for (k = j+1; k < len; k++)
				if (dna_array[i].dna[j] > dna_array[i].dna[k])
					dna_array[i].inver ++;
		}
	}
	
	qsort(dna_array, num, sizeof(dna_seq), cmp_dna);
	
	for (i = 0; i < num; i++)
	{
		printf("%s\n", dna_array[i].dna);
		free(dna_array[i].dna);
	}
	
	free (dna_array);
	
	return 0;
}
