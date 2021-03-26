#include <cstring>
#include <iostream>
using namespace std;
#define DEBUG

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int row, col, number = 1, opeTimes, queTimes, queRow, queCol;
    while (scanf("%d%d", &row, &col) == 2 && row) {
        printf("Spreadsheet #%d\n", number);
        scanf("%d", &opeTimes);
        for (int i = 0; i < opeTimes; ++i) {
        }
        scanf("%d", &queTimes);
        while (queTimes--) {
            scanf("%d%d", &queRow, &queCol);
            memcpy()
        }
    }
    return 0;
}