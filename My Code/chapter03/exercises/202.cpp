#include <assert.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;
#define DEBUG

const int MAXN = 3005;
map<int, int> Pos;

void solve(int n, const int d, string& ans, int& r) {
    assert(n % d && n < d);
    ans = ".";
    Pos.clear();
    while (true) {
        n *= 10;
        int p = Pos[n];
        if (!p)
            Pos[n] = ans.size();
        else {
            r = ans.size() - p;
            if (r >= 50) {
                ans.erase(p + 50);
                ans += "...";
            }
            ans.insert(p, "(");
            ans += ")";
            break;
        }
        ans += (char)(n / d + '0');
        n %= d;
        if (!n) {
            ans += "(0)";
            r = 1;
            break;
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int a, b;
    while (scanf("%d%d", &a, &b) == 2) {
        string ans = ".(0)";
        int r = 1;
        if (a % b)
            solve(a % b, b, ans, r);
        printf("%d/%d = %d%s\n", a, b, a / b, ans.c_str());
        printf("   %d = number of digits in repeating cycle\n\n", r);
    }
    return 0;
}