#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define LOCAL

int main() {
#ifdef LOCAL
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    char s[100];
    int flag = 1;
    while (T--) {
        if (flag)
            flag = 0;
        else
            printf("\n");
        scanf("%s", s);
        int len = strlen(s);
        for (int i = 1; i <= len; ++i) {
            if (len % i == 0) {
                int flag = 1;
                for (int j = 0; j < i; ++j) {
                    for (int k = j + i; k < len; k += i) {
                        if (s[k] != s[j]) {
                            flag = 0;
                            break;
                        }
                    }
                    if (!flag)
                        break;
                }
                if (flag) {
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }
    return 0;
}