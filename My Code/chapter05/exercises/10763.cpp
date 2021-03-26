#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// #define DEBUG

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, a, b;
    pair<int, int> p;
    set<pair<int, int>> s;
    while (scanf("%d", &n) && n) {
        s.clear();
        while (n--) {
            cin >> a >> b;
            p.first = min(a, b);
            p.second = max(a, b);
            if (s.count(p))
                s.erase(p);
            else
                s.insert(p);
        }
        if (s.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}