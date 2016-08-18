#include <stdio.h>
#include <string.h>

int solve(char *num)
{
    int i, j, k, x, len = strlen(num);
    for (i = 0; i < len-2; i++) {
        for (j = i+1; j < len-1; j++) {
            for (k = j+1; k < len; k++) {
                x = (num[i]-'0')*100 + (num[j]-'0')*10 + num[k]-'0';
                if (x % 8 == 0) {
                    return x;
                }
            }
        }
    }

    return -1;
}

int main()
{
    char num[103] = "00";
    scanf("%s", num+2);

    int ans = solve(num);
    if (ans >= 0) {
        printf("YES\n%d\n", ans);
    } 
    else {
        printf("NO\n");
    }

    return 0;
}
