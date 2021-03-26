#include <iostream>
using namespace std;
#define WIN "You win.\n"
#define LOSE "You lose.\n"
#define CHICK "You chickened out.\n"
#define DEBUG

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int number;
    char str1[256], str2[256];
    bool flag[26];
    while (scanf("%d", &number) == 1 && number != -1) {
        for (int i = 0; i < 26; ++i)
            flag[i] = false;
        printf("Round %d\n", number);
        scanf("%s%s", str1, str2);
        int idx = 0, count = 0;
        while (str1[idx])
            flag[str1[idx++] - 'a'] = true;
        idx = 0;
        while (str2[idx]) {
            if (!flag[str2[idx] - 'a'])
                ++count;
            else
                flag[str2[idx] - 'a'] = false;
            if (count > 6)
                break;
            ++idx;
        }
        if (str2[idx])
            printf(LOSE);
        else {
            for (idx = 0; idx < 26; ++idx)
                if (flag[idx]) {
                    printf(CHICK);
                    break;
                }
            if (idx >= 26)
                printf(WIN);
        }
    }
    return 0;
}