#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    char s[100];
    while (T--) {
        scanf("%s", s);
        int i = 0, count = 0, sum = 0;
        while (s[i]) {
            if (s[i++] == 'O')
                sum += ++count;
            else
                count = 0;
        }
        printf("%d\n", sum);
    }
    return 0;
}