#include <stdio.h>

int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int ans[10] = { 0 };
        for (int i = 1; i <= n; ++i) {
            int a = i;
            while (a) {
                ++ans[a % 10];
                a /= 10;
            }
        }
        for (int i = 0; i < 9; ++i) {
            printf("%d ", ans[i]);
        }
        printf("%d\n", ans[9]);
    }
    return 0;
}