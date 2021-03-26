#include <cstring>
#include <iostream>
using namespace std;
// #define DEBUG

int horizontal[10][10], vertical[10][10], n, N;

int statistic(int len) {
    int count = 0;
    //遍历每个左上角顶点
    for (int i = 1; i <= n - len; ++i) {
        for (int j = 1; j <= n - len; ++j) {
            bool flag = true;
            for (int x = i; x < i + len; ++x)
                if (!(vertical[x][j] && vertical[x][j + len])) {
                    flag = false;
                    break;
                }
            if (!flag)
                continue;
            for (int y = j; y < j + len; ++y)
                if (!(horizontal[i][y] && horizontal[i + len][y])) {
                    flag = false;
                    break;
                }
            if (!flag)
                continue;
            ++count;
        }
    }
    return count;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    char c;
    int x, y, kase = 0;
    while (scanf("%d%d", &n, &N) == 2) {
        for (int i = 0; i < 10; ++i) {
            memset(horizontal[i], 0, sizeof(horizontal[i]));
            memset(vertical[i], 0, sizeof(vertical[i]));
        }
        for (int i = 0; i < N; ++i) {
            getchar();
            scanf("%c%d%d", &c, &x, &y);
            if (c == 'H')
                horizontal[x][y] = 1;
            else
                vertical[y][x] = 1;
        }
        if (kase)
            printf("\n**********************************\n\n");
        printf("Problem #%d\n\n", ++kase);
        int totalFlag = 0;
        for (int i = 1; i < N; ++i) {
            int count = statistic(i);
            if (count) {
                totalFlag = 1;
                printf("%d square (s) of size %d\n", count, i);
            }
        }
        if (!totalFlag)
            printf("No completed squares can be found.\n");
    }
    return 0;
}