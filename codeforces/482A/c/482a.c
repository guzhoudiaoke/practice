#include <stdio.h>
#include <string.h>

#define MAX 100001

int visited[MAX];
int ans[MAX];

int main()
{
    memset(visited, 0, sizeof(int) * MAX);
    int n, k;
    scanf("%d %d", &n, &k);
    ans[1] = 1;
    visited[1] = 1;
    int index = 2;
    for (int i = k; i >= 1; i--) {
        if (ans[index-1] - i >= 1 && visited[ans[index-1] - i] == 0) {
            ans[index] = ans[index-1] - i;
        }
        else if(ans[index-1] + i <= n && visited[ans[index-1] + i] == 0) {
            ans[index] = ans[index-1] + i;
        }
        visited[ans[index]] = 1;
        index++;
    }
    int x = 2;
    for (int i = index; i <= n; i++) {
        for (; x <= n; x++) {
            if (visited[x] == 0) {
                ans[index] = x;
                visited[ans[index]] = 1;
                index++;
                break;
            }
        }
    }
    for (int i = 1; i < index; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
