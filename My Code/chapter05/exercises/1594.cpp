#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
// #define DEBUG

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int N, len;
    vector<int> num;
    set<vector<int>> s;
    scanf("%d", &N);
    while (N--) {
        num.clear();
        s.clear();
        scanf("%d", &len);
        bool flag = 1;
        for (int i = 0; i < len; ++i) {
            int tmp;
            scanf("%d", &tmp);
            num.push_back(tmp);
            if (tmp)
                flag = false;
        }
        while (!flag) {
            if (s.count(num)) {
                cout << "LOOP" << endl;
                break;
            }
            s.insert(num);
            flag = true;
            int first = num[0];
            for (int i = 0; i < len - 1; ++i) {
                num[i] = abs(num[i] - num[i + 1]);
                if (num[i])
                    flag = false;
            }
            num[len - 1] = abs(num[len - 1] - first);
            if (num[len - 1])
                flag = false;
        }
        if (flag)
            cout << "ZERO" << endl;
    }
    return 0;
}