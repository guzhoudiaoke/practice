#include <stdio.h>
#include <string.h>

int an[1001];
int ans[1001];
int is_prime[1001];

void init_prime(int n)
{
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= n; j+=i) {
                is_prime[j] = 0;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    init_prime(n);

    int index = 0;
    for (int i = 1; i <= n; i++) {
        if (is_prime[i]) {
            int q = 1;
            while (q <= n/i) {
                q *= i;
                ans[index++] = q;
            }
        }
    }

    printf("%d\n", index);
    for (int i = 0; i < index; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}
