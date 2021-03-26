#include <iostream>
using namespace std;
// #define DEBUG

pair<int, int> edges[6];

void mySort() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5 - i; ++j) {
            if (edges[j] > edges[j + 1])
                swap(edges[j], edges[j + 1]);
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    // freopen("d:\\output.txt", "w", stdout);
#endif
    int a, b, c;
    while (scanf("%d%d", &edges[0].first, &edges[0].second) == 2) {
        if (edges[0].first > edges[0].second)
            swap(edges[0].first, edges[0].second);
        for (int i = 1; i < 6; ++i) {
            scanf("%d%d", &edges[i].first, &edges[i].second);
            if (edges[i].first > edges[i].second)
                swap(edges[i].first, edges[i].second);
        }
        mySort();
        a = edges[0].first;
        b = edges[0].second;
        if (edges[1].first != a || edges[1].second != b) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        if (edges[2].first != a) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        c = edges[2].second;
        if (edges[3].first != a || edges[3].second != c) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        if (edges[4].first != b || edges[4].second != c || edges[5].first != b || edges[5].second != c) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        printf("POSSIBLE\n");
    }
    return 0;
}