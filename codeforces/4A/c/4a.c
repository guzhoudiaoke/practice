#include <stdio.h>

int main()
{
        unsigned int w;
        scanf("%u", &w);

        printf("%s", (w == 2 || (w % 2 == 1)) ? "NO" : "YES");
}
