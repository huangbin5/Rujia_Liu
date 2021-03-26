#include <iostream>
using namespace std;
// #define DEBUG

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    // freopen("d:\\output.txt", "w", stdout);
#endif
    char s[100024], t[100024];
    while (scanf("%s %s", s, t) == 2) {
        int si = 0, ti = 0;
        bool flag = true;
        while (s[si]) {
            while (t[ti] && t[ti] != s[si])
                ++ti;
            if (!t[ti]) {
                flag = false;
                break;
            }
            ++si;
            ++ti;
        }
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}