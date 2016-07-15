#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORD_LEN    128

int main()
{
    char word[MAX_WORD_LEN];
    char result[MAX_WORD_LEN * 2];

    bool is_vowel[26] = {false};
    is_vowel['a' - 'a'] = true;
    is_vowel['o' - 'a'] = true;
    is_vowel['y' - 'a'] = true;
    is_vowel['e' - 'a'] = true;
    is_vowel['u' - 'a'] = true;
    is_vowel['i' - 'a'] = true;

    scanf("%s", word);

    int len = strlen(word);
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] = word[i] - 'A' + 'a';
        }
        if (!is_vowel[word[i] - 'a']) {
            result[index++] = '.';
            result[index++] = word[i];
        }
    }
    result[index] = '\0';
    printf("%s\n", result);

    return 0;
}
