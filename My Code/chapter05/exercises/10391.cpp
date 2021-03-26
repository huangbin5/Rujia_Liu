#include <iostream>
#include <set>
#include <string>
using namespace std;
// #define DEBUG

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    set<string> words;
    string str;
    while (cin >> str)
        words.insert(str);
    for (set<string>::iterator it = words.begin(); it != words.end(); ++it) {
        str = *it;
        for (int i = 1; i < str.size(); ++i) {
            if (words.count(str.substr(0, i)) && words.count(str.substr(i))) {
                cout << str << endl;
                break;
            }
        }
    }
    return 0;
}