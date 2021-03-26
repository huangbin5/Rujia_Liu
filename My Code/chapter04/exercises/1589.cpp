#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
#define DEBUG

struct position {
    int x;
    int y;
};

struct red {
    char type;
    position pos;
};

int N, x, y, board[11][10];
red reds[7];

//检查帅
bool checkG(int x, int y, int xx, int yy) {
    if (y != yy)
        return true;
    for (int i = x + 1; i < xx; ++i)
        if (board[i][y])
            return true;
    return false;
}

//检查车
bool checkR(int x, int y, int xx, int yy) {
    if ((y != yy && x != xx) || (x == xx && y == yy))
        return true;
    if (y == yy)
        for (int i = min(x, xx) + 1; i < max(x, xx); ++i)
            if (board[i][y])
                return true;
    if (x == xx)
        for (int i = min(y, yy) + 1; i < max(y, yy); ++i)
            if (board[x][i])
                return true;
    return false;
}

//检查马
bool checkH(int x, int y, int xx, int yy) {
    if (abs(y - yy) == 1 && abs(x - xx) == 2 && !board[(x + xx) >> 1][yy])
        return false;
    if (abs(x - xx) == 1 && abs(y - yy) == 2 && !board[xx][(y + yy) >> 1])
        return false;
    return true;
}

//检查炮
bool checkC(int x, int y, int xx, int yy) {
    int count = 0;
    if (y == yy && x != xx)
        for (int i = min(x, xx) + 1; i < max(x, xx); ++i)
            if (board[i][y])
                ++count;
    if (x == xx && y != yy)
        for (int i = min(y, yy) + 1; i < max(y, yy); ++i)
            if (board[x][i])
                ++count;
    return count != 1;
}

bool check(int x, int y) {
    //检查每一颗棋子
    for (int i = 0; i < N; ++i) {
        switch (reds[i].type) {
        case 'G':
            if (!checkG(x, y, reds[i].pos.x, reds[i].pos.y))
                return false;
            break;
        case 'R':
            if (!checkR(x, y, reds[i].pos.x, reds[i].pos.y))
                return false;
            break;
        case 'H':
            if (!checkH(x, y, reds[i].pos.x, reds[i].pos.y))
                return false;
            break;
        case 'C':
            if (!checkC(x, y, reds[i].pos.x, reds[i].pos.y))
                return false;
            break;
        default:
            break;
        }
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    while (scanf("%d%d%d", &N, &x, &y) == 3 && N) {
        for (int i = 0; i < 11; ++i)
            memset(board[i], 0, sizeof(board[i]));
        for (int i = 0; i < N; ++i) {
            getchar();
            scanf("%c%d%d", &reds[i].type, &reds[i].pos.x, &reds[i].pos.y);
            board[reds[i].pos.x][reds[i].pos.y] = 1;
        }
        //依次检查4个方向
        if ((x - 1 > 0 && check(x - 1, y)) || (x + 1 < 4 && check(x + 1, y)) || (y - 1 > 3 && check(x, y - 1))
            || (y + 1 < 7 && check(x, y + 1))) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }
    return 0;
}