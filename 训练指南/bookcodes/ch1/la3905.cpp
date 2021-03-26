// LA3905 Meteor
// Rujia Liu
#include<cstdio>
#include<algorithm>
using namespace std;
// 0<x+at<w
void update(int x, int a, int w, double& L, double& R) {
  if(a == 0) {
    if(x <= 0 || x >= w) R = L-1; // 无解
  } else if(a > 0) {
    L = max(L, -(double)x/a);
    R = min(R, (double)(w-x)/a);
  } else {
    L = max(L, (double)(w-x)/a);
    R = min(R, -(double)x/a);
  }
}

const int maxn = 100000 + 10;

struct Event {
  double x;
  int type;
  bool operator < (const Event& a) const {
    return x < a.x || (x == a.x && type > a.type); // 先处理右端点
  }
} events[maxn*2];

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int w, h, n, e = 0;
    scanf("%d%d%d", &w, &h, &n);
    for(int i = 0; i < n; i++) {
      int x, y, a, b;
      scanf("%d%d%d%d", &x, &y, &a, &b);
      // 0<x+at<w, 0<y+bt<h, t>=0
      double L = 0, R = 1e9;
      update(x, a, w, L, R);
      update(y, b, h, L, R);
      if(R > L) {
        events[e++] = (Event){L, 0};
        events[e++] = (Event){R, 1};
      }
    }
    sort(events, events+e);
    int cnt = 0, ans = 0;
    for(int i = 0; i < e; i++) {
      if(events[i].type == 0) ans = max(ans, ++cnt);
      else cnt--;
    }
    printf("%d\n", ans);
  }
  return 0;
}
