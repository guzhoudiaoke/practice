#include <cstdio>
#include <queue>
using namespace std;

int main()
{
    queue<int> first;
    queue<int> second;

    int n, k1, k2;
    scanf("%d", &n);

    int x;
    scanf("%d", &k1);
    for (int i = 0; i < k1; i++) {
        scanf("%d", &x);
        first.push(x);
    }
    scanf("%d", &k2);
    for (int i = 0; i < k2; i++) {
        scanf("%d", &x);
        second.push(x);
    }

    int max = 1;
    for (int i = 1; i <= n+1; i++) {
        max *= i;
    }

    int ans = 1;
    int cnt = 0;
    while (1) {
        if (first.empty() || second.empty()) {
            break;
        }
        int f = first.front();
        int s = second.front();
        first.pop();
        second.pop();

        if (f > s) {
            first.push(s);
            first.push(f);
        }
        else {
            second.push(f);
            second.push(s);
        }

        cnt++;
        if (cnt > max) {
            ans = 0;
            break;
        }
    }

    if (ans == 0) {
        printf("-1\n");
    }
    else {
        if (first.empty()) ans = 2;
        printf("%d %d\n", cnt, ans);
    }

    return 0;
}

