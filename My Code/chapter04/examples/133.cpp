#include <iostream>
using namespace std;
// #define DEBUG

bool flag[25];
int n, k, m;

int selectOne(int start, int direction) {
    int step = direction == 1 ? k : m;
    while (step > 0) {
        start += direction;
        if (start > n || start < 1)
            start -= direction * n;
        if (flag[start])
            --step;
    }
    return start;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    while (scanf("%d%d%d", &n, &k, &m) == 3 && n) {
        for (int i = 1; i <= n; ++i)
            flag[i] = true;
        int left = n, first = n, second = 1;
        while (left) {
            first = selectOne(first, 1);
            second = selectOne(second, -1);
            if (first == second) {
                --left;
                printf("%3d", first);
                flag[first] = false;
            } else {
                left -= 2;
                printf("%3d%3d", first, second);
                flag[first] = flag[second] = false;
            }
            if (left)
                printf(",");
        }
        puts("");
    }
    return 0;
}