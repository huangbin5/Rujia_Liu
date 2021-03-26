#include <stdio.h>
#define maxn 1010

int main() {
    int n;
    int kase = 0;
    while (scanf("%d", &n) == 1 && n) {
        printf("Game %d:\n", ++kase);
        int ans[maxn];
        int ans_count[10] = { 0 };
        for (int i = 0; i < n; ++i) {
            scanf("%d", &ans[i]);
            ++ans_count[ans[i]];
        }
        while (1) {
            int data[maxn];
            int data_count[10] = { 0 };
            int A = 0, B = 0;
            for (int i = 0; i < n; ++i) {
                scanf("%d", &data[i]);
                ++data_count[data[i]];
                if (ans[i] == data[i])
                    ++A;
            }
            if (data[0] == 0)
                break;
            for (int i = 0; i < 10; ++i) {
                B += ans_count[i] < data_count[i] ? ans_count[i] : data_count[i];
            }
            printf("    (%d,%d)\n", A, B - A);
        }
    }
    return 0;
}