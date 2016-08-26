#include <cstdio>
#include <cstring>

int main()
{
    char s[51];
    char t[51];
    scanf("%s", s);
    scanf("%s", t);

    int pos = 0;
    for (int i = 0; i < strlen(t); i++) {
        if (t[i] == s[pos]) {
            pos++;
        }
    }
    printf("%d\n", pos+1);
    return 0;
}
