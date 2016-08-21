#include <stdio.h>
#include <string.h>

int main()
{
    int n, m;
    scanf("%d %d\n", &n, &m);

    char pixel;
    int colored = 0;
    for (int i = 0; i < n; i++) {
        char line[202] = {0};
        fgets(line, 200, stdin);
        for (int j = 0; j < strlen(line); j++) {
            pixel = line[j];
            if (pixel == 'C' || pixel == 'M' || pixel == 'Y') {
                colored = 1;
                break;
            }
        }
        if (colored == 1) {
            break;
        }
    }

    if (colored == 1) {
        printf("#Color\n");
    }
    else {
        printf("#Black&White\n");
    }

    return 0;
}
