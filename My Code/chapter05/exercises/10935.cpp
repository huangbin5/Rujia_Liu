#include <iostream>
#include <queue>
using namespace std;
// #define DEBUG

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n;
    while (scanf("%d", &n) && n) {
        queue<int> q;
        for (int i = 1; i <= n; ++i)
            q.push(i);
        cout << "Discarded cards:";
        bool first = true;
        while (q.size() > 1) {
            if (first)
                first = false;
            else
                cout << ",";
            cout << " " << q.front();
            q.pop();
            q.push(q.front());
            q.pop();
        }
        puts("");
        cout << "Remaining card: " << q.front() << endl;
    }
    return 0;
}