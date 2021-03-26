#include <stdio.h>
// #define DEBUG

char data[15][15];
int num[15][15];
int flag[15][15];
int row, col;

void clear() {
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            num[i][j] = 0;
            flag[i][j] = 0;
        }
    }
}

void setNum() {
    int count = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (data[i][j] != '*' && (i == 0 || j == 0 || data[i - 1][j] == '*' || data[i][j - 1] == '*'))
                num[i][j] = ++count;
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int count = 0;
    while (scanf("%d", &row) == 1 && row != 0) {
        clear();
        scanf("%d", &col);
        for (int i = 0; i < row; ++i) {
            scanf("%s", data[i]);
        }
        setNum();
        if (count)
            puts("");
        printf("puzzle #%d:\n", ++count);
        //横向
        printf("Across\n");
        int begin = 1;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (begin && num[i][j]) {
                    begin = 0;
                    printf("%3d.%c", num[i][j], data[i][j]);
                } else if (!begin && data[i][j] == '*') {
                    begin = 1;
                    puts("");
                } else if (data[i][j] != '*') {
                    putchar(data[i][j]);
                }
            }
            if (!begin) {
                begin = 1;
                puts("");
            }
        }
        //纵向
        printf("Down\n");
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (num[i][j] && !flag[i][j]) {
                    printf("%3d.%c", num[i][j], data[i][j]);
                    int k;
                    for (k = i + 1; k < row; ++k) {
                        if (data[k][j] == '*') {
                            puts("");
                            break;
                        } else {
                            putchar(data[k][j]);
                            flag[k][j] = 1;
                        }
                    }
                    if (k == row)
                        puts("");
                }
            }
        }
    }
    return 0;
}