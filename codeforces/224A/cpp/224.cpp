#include <cstdio>
#include <cmath>

int main()
{
    long long s1, s2, s3;
    scanf("%lld %lld %lld", &s1, &s2, &s3);

    long long a, b, c;
    a = sqrt(s1*s2/s3);
    b = sqrt(s1*s3/s2);
    c = sqrt(s2*s3/s1);

    printf("%lld\n", 4*(a+b+c));
}
