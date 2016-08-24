#include <stdio.h>

int main()
{
    int digital[10] = { 2, 7, 2, 3, 3, 4, 2, 5, 1, 2 };
    char n[3];
    scanf("%s", n);
    printf("%d\n", digital[n[0] - '0'] * digital[n[1] - '0']);
    return 0;
}
