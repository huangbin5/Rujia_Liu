#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
// #define DEBUG

struct position {
    int x;
    int y;
};

int N, wCount, bCount;
char board[9][9], current, command;
position rc, direction[8] = { { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 } };
vector<position> cadidates;

bool checkOne(int x, int y, bool& flag, bool& first) {
    if (first && (board[x][y] == '-' || board[x][y] == current)) {
        flag = false;
        return true;
    }
    first = false;
    if (board[x][y] == '-') {
        flag = false;
        return true;
    }
    if (board[x][y] == current)
        return true;
    return false;
}

void setBoard(int x, int y, int xx, int yy) {
    int xStep = x == xx ? 0 : (x > xx ? -1 : 1);
    int yStep = y == yy ? 0 : (y > yy ? -1 : 1);
    for (int i = x + xStep, j = y + yStep; i != xx || j != yy; i += xStep, j += yStep)
        board[i][j] = current;
    int count = max(abs(x - xx) - 1, abs(y - yy) - 1);
    if (current == 'W') {
        wCount += count;
        bCount -= count;
    } else {
        wCount -= count;
        bCount += count;
    }
}

bool check(int x, int y, bool change) {
    bool flag, first;
    for (int idx = 0; idx < 8; ++idx) {
        flag = true, first = true;
        int xx = direction[idx].x, yy = direction[idx].y;
        for (int i = x + xx, j = y + yy; i > 0 && i < 9 && j > 0 && j < 9; i += xx, j += yy)
            if (checkOne(i, j, flag, first))
                if (flag)
                    if (change) {
                        setBoard(x, y, i, j);
                        break;
                    } else
                        return true;
                else
                    break;
    }
    return false;
}

void getCadidates() {
    cadidates.clear();
    for (int i = 1; i < 9; ++i)
        for (int j = 1; j < 9; ++j)
            if (board[i][j] == '-' && check(i, j, false))
                cadidates.push_back({ i, j });
}

void printCadidates() {
    if (cadidates.empty())
        printf("No legal move.");
    else {
        for (vector<position>::iterator it = cadidates.begin(); it != cadidates.end(); ++it) {
            if (it != cadidates.begin())
                printf(" ");
            printf("(%d,%d)", it->x, it->y);
        }
    }
    puts("");
}

void exchangeCurrent() { current = current == 'W' ? 'B' : 'W'; }

void putDown() {
    check(rc.x, rc.y, true);
    board[rc.x][rc.y] = current;
    if (current == 'W')
        ++wCount;
    else
        ++bCount;

    printf("Black - %d White - %d\n", bCount, wCount);
    exchangeCurrent();
}

void printBoard() {
    for (int i = 1; i < 9; ++i) {
        for (int j = 1; j < 9; ++j)
            putchar(board[i][j]);
        puts("");
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &N);
    bool first = true;
    while (N--) {
        if (!first)
            puts("");
        wCount = 0, bCount = 0;
        for (int i = 1; i < 9; ++i) {
            getchar();
            for (int j = 1; j < 9; ++j) {
                board[i][j] = getchar();
                if (board[i][j] == 'W')
                    ++wCount;
                if (board[i][j] == 'B')
                    ++bCount;
            }
        }
        getchar();
        current = getchar();
        while (getchar()) {
            command = getchar();
            switch (command) {
            case 'L':
                getCadidates();
                printCadidates();
                break;
            case 'M':
                rc.x = getchar() - '0';
                rc.y = getchar() - '0';
                getCadidates();
                if (cadidates.empty())
                    exchangeCurrent();
                putDown();
                break;
            case 'Q':
                printBoard();
                break;
            default:
                break;
            }
            if (command == 'Q')
                break;
        }
        first = false;
    }
    return 0;
}