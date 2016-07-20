/*
 * poj 2513
 * guzhoudiaoke@126.com
 * 2011-09-07
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX	500000

typedef struct tire_tree {
	int index;		// 每种颜色的索引
	struct tire_tree *next[27];
}tire_tree;

tire_tree *root;
int color_degree[MAX+1];	// 每种颜色看作一个节点，该数组表示节点的度
int total_num = 1;

// 下面定义并查集
int father[MAX+1] = { 0 };	// father[x] 表示x 的父节点
int rank[MAX+1];		// rank[x] 表示x 的秩

void tire_create(tire_tree **node)
{
	(*node) = (tire_tree *)malloc(sizeof(tire_tree));
	int i;
	for (i = 0; i < 27; i++)
		(*node)->next[i] = NULL;
	(*node)->index = 0;
}

void tire_insert(char *color)
{
	tire_tree *p = root;
	int len = strlen(color);
	int i;
	for (i = 0; i < len; i++)
	{
		int pos = color[i] - 'a';
		if (p->next[pos] == NULL)
			tire_create(&(p->next[pos]));
		p = p->next[pos];
	}
	if (p->index == 0)
		p->index = total_num++;
}

int tire_search(char *color)
{
	tire_tree *p = root;
	int len = strlen(color);
	int i;
	for (i = 0; i < len; i++)
		p = p->next[color[i]-'a'];
	
	return p->index;
}

// 初始化集合
void make_set(int x)
{
	father[x] = x;		// 根据实际情况指定的父节点可变化
	rank[x] = 0;		// 根据实际情况初始化秩也有所变化
}

// 查找x 元素所在的集合，回溯时压缩路径
int find_set(int x)
{
	if (x != father[x])
		father[x] = find_set(father[x]);
	return father[x];
}

// 按秩合并x, y所在的集合，if else结构不是绝对的，具体根据情况变化
// 但是，宗旨不变，按秩合并，实时更新秩
void union_set(int x, int y)
{
	x = find_set(x);
	y = find_set(y);
	if (x == y) return;
	if (rank[x] > rank[y])
		father[y] = x;
	else
	{
		if (rank[x] == rank[y])
			rank[y] ++;
		father[x] = y;
	}
}

int main()
{
	char color_l[11], color_r[11];
	int i;
	
	tire_create(&root);
	memset(color_degree, 0, sizeof(color_degree));

	while (scanf("%s%s", color_l, color_r) != EOF)
	{
		tire_insert(color_l);
		tire_insert(color_r);
		int x = tire_search(color_l);
		int y = tire_search(color_r);
		color_degree[x]++;
		color_degree[y]++;
		
		if (father[x] == 0) make_set(x);
		if (father[y] == 0) make_set(y);
		
		union_set(x, y);
	}
	
	int sum = 0;
	int father_1 = find_set(1);
	for (i = 1; i < total_num; i++)
	{
		if (color_degree[i]%2 != 0) sum++;
		if (sum > 2) 
		{
			printf("Impossible\n");
			return 0;
		}
		if(find_set(i) != father_1)  
		{  
			printf("Impossible\n");  
			return 0;  
		}
	}
	
	printf("Possible\n");  

	return 0;
}

