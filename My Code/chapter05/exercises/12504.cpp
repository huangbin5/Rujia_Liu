#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
// #define DEBUG

map<string, string> oldDic;
map<string, string> newDic;
set<string> oldKeys;
set<string> newKeys;

void readOneLine(map<string, string>& dic, set<string>& keys) {
    string line;
    cin >> line;
    int curPos = 1, firPos, secPos, lastPos = line.size() - 1;
    for (;;) {
        firPos = line.find(':', curPos);
        secPos = line.find(',', curPos);
        if (firPos == -1)
            break;
        if (secPos == -1) {
            secPos = lastPos;
            lastPos = -1;
        }
        dic[line.substr(curPos, firPos - curPos)] = line.substr(firPos + 1, secPos - firPos - 1);
        keys.insert(line.substr(curPos, firPos - curPos));
        curPos = secPos + 1;
        if (lastPos == -1)
            break;
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int N;
    scanf("%d", &N);
    while (N--) {
        oldDic.clear();
        newDic.clear();
        oldKeys.clear();
        newKeys.clear();
        readOneLine(oldDic, oldKeys);
        readOneLine(newDic, newKeys);
        set<string> inSet, outSet, modSet;
        set_difference(newKeys.begin(), newKeys.end(), oldKeys.begin(), oldKeys.end(), inserter(inSet, inSet.begin()));
        set_difference(oldKeys.begin(), oldKeys.end(), newKeys.begin(), newKeys.end(), inserter(outSet, outSet.begin()));
        set_intersection(oldKeys.begin(), oldKeys.end(), newKeys.begin(), newKeys.end(), inserter(modSet, modSet.begin()));
        bool empty = true, first;
        if (inSet.size()) {
            empty = false;
            first = true;
            for (set<string>::iterator it = inSet.begin(); it != inSet.end(); ++it) {
                if (first) {
                    cout << '+' << *it;
                    first = false;
                } else
                    cout << ',' << *it;
            }
            puts("");
        }
        if (outSet.size()) {
            empty = false;
            first = true;
            for (set<string>::iterator it = outSet.begin(); it != outSet.end(); ++it) {
                if (first) {
                    cout << '-' << *it;
                    first = false;
                } else
                    cout << ',' << *it;
            }
            puts("");
        }
        if (modSet.size()) {
            first = true;
            for (set<string>::iterator it = modSet.begin(); it != modSet.end(); ++it) {
                if (oldDic[*it] == newDic[*it])
                    continue;
                empty = false;
                if (first) {
                    cout << '*' << *it;
                    first = false;
                } else
                    cout << ',' << *it;
            }
            if (!first)
                puts("");
        }
        if (empty)
            cout << "No changes" << endl;
        puts("");
    }
    return 0;
}