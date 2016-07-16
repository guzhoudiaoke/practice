#include <stdio.h>
#include <string.h>

#define MAX_LEN 128

void to_lower(char *s)
{
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
    }
}

int main()
{
    char a[MAX_LEN] = {0};
    char b[MAX_LEN] = {0};
    scanf("%s", a);
    to_lower(a);
    scanf("%s", b);
    to_lower(b);

    int result = strcmp(a, b);
    if (result == 0)
        printf("0\n");
    else if (result < 0)
        printf("-1\n");
    else 
        printf("1\n");

    return 0;
}
