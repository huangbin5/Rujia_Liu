#include <limits.h>
#include <stdio.h>
#define DEBUG

int freq[255][1005];
int count, m, n;
char data[55][1005];

void clear() {
    for (int i = 0; i < 255; ++i) {
        for (int j = 0; j < 1005; ++j) {
            freq[i][j] = 0;
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    // freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &count);
    while (count--) {
        clear();
        scanf("%d %d", &m, &n);
        for (int i = 0; i < m; ++i) {
            scanf("%s", data[i]);
        }
        int minDis = 0;
        for (int j = 0; j < n; ++j) {
            int maxFreq = 0;
            char maxChar;
            for (int i = 0; i < m; ++i) {
                ++freq[data[i][j]][j];
                if (freq[data[i][j]][j] > maxFreq || freq[data[i][j]][j] == maxFreq && data[i][j] < maxChar) {
                    maxFreq = freq[data[i][j]][j];
                    maxChar = data[i][j];
                }
            }
            putchar(maxChar);
            minDis += m - maxFreq;
        }
        printf("\n%d\n", minDis);
    }
    return 0;
}