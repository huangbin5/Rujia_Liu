#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <sstream>
#include <stdbool.h>
#include <string>
#include <time.h>
#include <vector>
using namespace std;
#define maxn 10000000 + 10
#define _for(i, a, b) for (int i = (a); i < (b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    string s = "hellohello";
    cout << (s.find('w')==-1) << endl;
    cout <<(int) s.find('h', 6) << endl;
    system("pause");
    return 0;
}