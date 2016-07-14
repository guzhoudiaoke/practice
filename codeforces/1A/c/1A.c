#include <stdio.h>

typedef unsigned long long u64;
inline u64 div_up(u64 n, u64 base)
{
        return (n + base - 1) / base;
}

inline u64 calc(u64 m, u64 n, u64 a)
{
        u64 x = div_up(m, a);
        u64 y = div_up(n, a);
        return x*y;
}

int main()
{
        u64 m, n, a;
        scanf("%I64u %I64u %I64u", &m, &n, &a);

        u64 num = calc(m, n, a);
        printf("%I64u\n", num);

        return 0;
}
