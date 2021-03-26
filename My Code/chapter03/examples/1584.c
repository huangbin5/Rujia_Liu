#include <stdio.h>
#include <string.h>
#define maxn 105

int update(char* s, int pos, int cur) {
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        if (s[(pos + i) % len] != s[(cur + i) % len])
            return s[(pos + i) % len] > s[(cur + i) % len];
    }
    return 0;
}

int main() {
    int num;
    scanf("%d", &num);
    char s[maxn];
    while (num--) {
        scanf("%s", s);
        int pos = 0, len = strlen(s);
        for (int i = 0; i < len; ++i) {
            if (update(s, pos, i))
                pos = i;
        }
        for (int i = 0; i < len; ++i) {
            putchar(s[(pos + i) % len]);
        }
        printf("\n");
    }
    return 0;
}