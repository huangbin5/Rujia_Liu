#include <cmath>
#include <iostream>
#include <set>
using namespace std;
// #define DEBUG

struct point {
    int x;
    int y;
    bool operator<(const point p) const { return x < p.x || x == p.x && y < p.y; }
};

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int N, num, sum;
    float avg;
    point p;
    set<point> s;
    scanf("%d", &N);
    while (N--) {
        sum = 0;
        s.clear();
        scanf("%d", &num);
        for (int i = 0; i < num; ++i) {
            scanf("%d%d", &p.x, &p.y);
            s.insert(p);
            sum += p.x;
        }
        avg = (float)sum / num;
        bool flag = true;
        for (set<point>::iterator it = s.begin(); it != s.end(); ++it) {
            p = *it;
            float x = 2 * avg - p.x;
            if (x - (float)(int)x > 1e-7) {
                flag = false;
                break;
            }
            p.x = (int)round(x);
            if (!s.count(p)) {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}