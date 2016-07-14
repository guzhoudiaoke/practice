#include <stdio.h>
#include <string.h>

#define MAX_LEN         128
#define LONG_WORD_LEN   10

int main()
{
        char word[MAX_LEN];
        int n, len;
        scanf("%d", &n);

        while (n) {
                scanf("%s", word);
                len = strlen(word);

                if (len > LONG_WORD_LEN) {
                        printf("%c%d%c\n", word[0], len-2, word[len-1]);
                }
                else {
                        printf("%s\n", word);
                }

                n--;
        }
}
