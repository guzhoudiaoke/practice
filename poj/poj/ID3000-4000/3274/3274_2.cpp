#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;
#define MAXHASH 99983
#define NN 100003
#define KK 33
int N, K;
int head[MAXHASH], nxt[NN];
int a[NN], c[NN][KK];
int sum[NN][KK];

int hash(int v[]){
    int h = 0;
    int i;
    for (i = 1; i <= K; i++)
    {
        h = ((h << 2) + (v[i] >> 4))^(v[i] << 10);
    }
    h = h % MAXHASH;
    h = h < 0 ? h + MAXHASH : h;
    return h;
}
int main() 
{
    int temp, i, j;
    scanf("%d%d", &N, &K);
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &a[i]);
    }
    memset(sum, 0, sizeof(sum));
    for (i = 1; i <= N; i++)
    {
        temp = a[i];
        for (j = 1; j <= K; j++)
        {
            sum[i][j] = sum[i - 1][j] + temp % 2;
            temp /= 2;
        }
    }

    int ans = 0;

    memset(head, -1, sizeof(head));
    for (i = 0; i <= N; i++){ //这里从0开始
        for (j = 1; j <= K; j++) c[i][j] = sum[i][j] - sum[i][1];
        int h = hash(c[i]);
        bool find = 0;
        for (int p = head[h]; p != -1; p = nxt[p]){
            for (j = 1; j <= K; j++){
                if(c[i][j] != c[p][j]) break;
            }
            if(j > K){
                if(i - p > ans) ans = i - p;
                find = 1;
                break;
            }
        }
        if(!find){
            nxt[i] = head[h];
            head[h] = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
