#include <ctype.h>
#include <stdio.h>
#include <string.h>
const char* arr = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* result[] = { "is not a palindrome.", "is a regular palindrome.", "is a mirrored string.", "is a mirrored palindrome." };

char mir(char c) {
    if (isalpha(c))
        return arr[c - 'A'];
    else
        return arr[c - '0' + 25];
}

int main() {
    char s[25];
    while (scanf("%s", s) == 1) {
        int p = 1, m = 1;
        int len = strlen(s);
        for (int i = 0; i<(len + 1)>> 1; ++i) {
            if (s[i] != s[len - 1 - i])
                p = 0;
            if (mir(s[i]) != s[len - 1 - i])
                m = 0;
        }
        printf("%s -- %s\n\n", s, result[2 * m + p]);
    }
    return 0;
}