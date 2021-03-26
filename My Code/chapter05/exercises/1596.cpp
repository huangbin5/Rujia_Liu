#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
// #define DEBUG

map<char, int> sizeMap;
map<char, map<int, int>> valueMap;

int caculSize(const string& s, int startPos, int endPos) {
    int ans = 0;
    for (int i = startPos + 1; i < endPos; ++i)
        ans = ans * 10 + (s[i] - '0');
    return ans;
}

int caculIndex(string& s, int n) {
    for (int i = s.size() - 1; i >= 0; --i) {
        if (n >= sizeMap[s[i]])
            return -1;
        if (valueMap[s[i]].count(n) == 0)
            return -1;
        n = valueMap[s[i]][n];
    }
    return n;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    string exp;
    int lineNum = 0;
    bool flag = false, over = false;
    while (getline(cin, exp)) {
        if (exp == ".") {
            if (!(over || flag))
                cout << 0 << endl;
            sizeMap.clear();
            valueMap.clear();
            lineNum = 0;
            flag = false;
            over = true;
            continue;
        }
        if (flag)
            continue;
        over = false;
        ++lineNum;
        int equalPos = exp.find('=');
        if (equalPos == -1) {
            int startPos = exp.find('['), endPos = exp.find(']');
            int size = caculSize(exp, startPos, endPos);
            sizeMap[exp[startPos - 1]] = size;
            valueMap[exp[startPos - 1]] = map<int, int>();
        } else {
            string preExp = exp.substr(0, equalPos);
            int startPos = preExp.find_last_of('['), endPos = preExp.find(']');
            int preNum = caculSize(preExp, startPos, endPos);
            int preIndex;
            if (startPos > 1) {
                string preStr = "";
                for (int i = 2; i < startPos; i += 2)
                    preStr += preExp[i];
                preIndex = caculIndex(preStr, preNum);
            } else
                preIndex = preNum;
            if (preIndex < 0 || preIndex >= sizeMap[preExp[0]]) {
                cout << lineNum << endl;
                flag = true;
                continue;
            }
            string sufExp = exp.substr(equalPos + 1);
            startPos = sufExp.find_last_of('[');
            endPos = sufExp.find(']');
            int sufIndex;
            if (startPos > 0) {
                int sufNum = caculSize(sufExp, startPos, endPos);
                string sufStr = "";
                for (int i = 0; i < startPos; i += 2)
                    sufStr += sufExp[i];
                sufIndex = caculIndex(sufStr, sufNum);
            } else
                sufIndex = caculSize(sufExp, -1, sufExp.size());
            if (sufIndex < 0) {
                cout << lineNum << endl;
                flag = true;
                continue;
            }
            valueMap[preExp[0]][preIndex] = sufIndex;
        }
    }
    return 0;
}