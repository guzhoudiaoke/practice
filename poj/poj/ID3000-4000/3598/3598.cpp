/*
 * problem: poj 3598
 * author:	guzhoudiaoke
 * time:	2011-10-05
 */

#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <vector>
using namespace std;

typedef struct cart {
	int v;
	int w;
} cart;

vector<vector<cart> > class_vec;

int n;
cart carts[100000];

int cmp_cart(const void *a, const void *b)
{
	if (((cart *)b)->v != ((cart *)a)->v)
		return ((cart *)b)->v - ((cart *)a)->v;
	else
		return ((cart *)b)->w - ((cart *)a)->w;
}

int main()
{
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d %d", &carts[i].v, &carts[i].w);
	qsort(carts, n, sizeof(cart), cmp_cart);

	class_vec.push_back(vector<cart>(1, carts[0]));
	
	for (i = 1; i < n; i++)
	{
		if (carts[i].w <= class_vec.back().back().w)
			class_vec.push_back(vector<cart>(1, carts[i]));
		else
		{
			int start = 0;
			int end = class_vec.size()-1;
			while (start <= end)
			{
				int middle = (start+end) / 2;
				if (class_vec[middle].back().w >= carts[i].w)
					start = middle + 1;
				else
					end = middle - 1;
			}
			class_vec[start].push_back(carts[i]);
		}
	}

	vector<vector<cart> >::iterator it = class_vec.begin();
	while (it != class_vec.end())
	{
		printf("%d:", it->size());
		vector<cart>::reverse_iterator rit = it->rbegin();
		while (rit != it->rend())
		{
			printf(" (%d,%d)", rit->v, rit->w);
			rit++;
		}
		printf("\n");
		it++;
	}

	return 0;
}