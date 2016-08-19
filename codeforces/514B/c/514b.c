#include <stdio.h>

struct point {
    int x;
    int y;
};

struct point pts[1001];
int died[1001];

int same_line(int x0, int y0, struct point pt1, struct point pt2)
{
    if ((pt1.y-y0)*(pt2.x-x0) == (pt2.y-y0)*(pt1.x-x0)) {
        return 1;
    }
    return 0;
}

int solve(int n, int x0, int y0)
{
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (died[i] == 1) {
            continue;
        }

        ans++;
        died[i] = 1;
        for (int j = 0; j < n; j++) {
            if (died[j] == 1) {
                continue;
            }
            if (same_line(x0, y0, pts[i], pts[j])) {
                died[j] = 1;
            }
        }
    }

    return ans;
}

int main()
{
    int n, x0, y0;
    scanf("%d %d %d", &n, &x0, &y0);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pts[i].x, &pts[i].y);
        died[i] = 0;
    }

    printf("%d\n", solve(n, x0, y0));
    return 0;
}
