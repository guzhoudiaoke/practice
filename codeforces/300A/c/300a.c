#include <stdio.h>
#include <stdlib.h>

int cmp(const void *left, const void *right)
{
    int *l = (int *)left;
    int *r = (int *)right;
    return *l - *r;
}

int main()
{
    int n;
    scanf("%d", &n);

    int an[101];
    for (int i = 0; i < n; i++) {
        scanf("%d", &an[i]);
    }

    qsort(an, n, sizeof(int), cmp);

    int s1 = 1, s2, s3 = 1;
    if (an[n-1] == 0) {
        s3 = 2;
    }
    s2 = n - s1 - s3;

    printf("%d %d\n", s1, an[0]);
    if (s3 == 1) {
        printf("%d %d\n", s3, an[n-1]);

        printf("%d ", s2);
        for (int i = 0; i < s2; i++) {
            printf("%d ", an[i+1]);
        }
    }
    else {
        printf("%d %d %d\n", s3, an[1], an[2]);

        printf("%d ", s2);
        for (int i = 0; i < s2; i++) {
            printf("%d ", an[i+3]);
        }
    }
    printf("\n");

    return 0;
}
