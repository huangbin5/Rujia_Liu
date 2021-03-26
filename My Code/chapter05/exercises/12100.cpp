#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// #define DEBUG

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int N, n, index;
    scanf("%d", &N);
    while (N--) {
        queue<int> priorities, indices;
        priority_queue<int> pq;
        scanf("%d%d", &n, &index);
        for (int i = 0; i < n; ++i) {
            int tmp;
            scanf("%d", &tmp);
            priorities.push(tmp);
            indices.push(i);
            pq.push(tmp);
        }
        int time = 0;
        for (;;) {
            while (priorities.front() != pq.top()) {
                priorities.push(priorities.front());
                priorities.pop();
                indices.push(indices.front());
                indices.pop();
            }
            ++time;
            if (indices.front() == index)
                break;
            priorities.pop();
            indices.pop();
            pq.pop();
        }
        cout << time << endl;
    }
    return 0;
}