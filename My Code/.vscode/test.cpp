#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <math.h>
#include <stdbool.h>
#include <string>
#include <time.h>
#include <vector>
using namespace std;
#define maxn 10000000 + 10
#define _for(i, a, b) for (int i = (a); i < (b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    string ans;
    srand(time(NULL));
    for (int i = 0; i < 97; ++i) {
        for (int j = 0; j < 20; ++j) {
            int n = rand() % 62;
            if (n < 26)
                ans += ('A' + n);
            else if (n < 52)
                ans += ('a' + n - 26);
            else
                ans += ('0' + n - 52);
        }
        ans += '/';
    }
    cout << ans << endl;
    system("pause");
    return 0;
}