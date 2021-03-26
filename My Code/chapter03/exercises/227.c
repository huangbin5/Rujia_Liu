#include <stdio.h>
// #define DBUGGER

int main() {
#ifdef DBUGGER
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int a[256], b[256];
    a['A'] = -1;
    a['B'] = 1;
    a['L'] = 0;
    a['R'] = 0;
    b['A'] = 0;
    b['B'] = 0;
    b['L'] = -1;
    b['R'] = 1;
    char puzzle[5][5];
    int row, col, count = 0, first = 1;
    for (;;) {
        //初始化
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                puzzle[i][j] = ' ';
            }
        }
        //输入
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                puzzle[i][j] = getchar();
                //结束
                if (!i && !j && 'Z' == puzzle[i][j])
                    return 0;
                if (puzzle[i][j] == ' ') {
                    row = i;
                    col = j;
                }
            }
            //换行
            getchar();
        }
        if (first)
            first = 0;
        else
            puts("");
        printf("Puzzle #%d:\n", ++count);
        //移动
        char move;
        int flag = 1;
        while ((move = getchar()) != '0') {
            if (move == '\n')
                continue;
            //非法
            if (move != 'A' && move != 'B' && move != 'L' && move != 'R' || row + a[move] < 0 || row + a[move] > 4 || col + b[move] < 0 || col + b[move] > 4) {
                flag = 0;
                while (getchar() != '0')
                    ;
                break;
            }
            //合法
            puzzle[row][col] = puzzle[row + a[move]][col + b[move]];
            row += a[move];
            col += b[move];
            puzzle[row][col] = ' ';
        }
        getchar();
        if (flag) {
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 4; ++j) {
                    printf("%c ", puzzle[i][j]);
                }
                printf("%c\n", puzzle[i][4]);
            }
        } else
            printf("This puzzle has no final configuration.\n");
    }
    return 0;
}