#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
// #define DEBUG

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    vector<int> length;
    vector<string> words[1005];
    int line = -1;
    string str;
    while (getline(cin, str)) {
        ++line;
        stringstream ss(str);
        int count = -1;
        while (ss >> str) {
            ++count;
            words[line].push_back(str);
            if (length.size() < count + 1)
                length.push_back(str.size());
            else if (length[count] < str.size())
                length[count] = str.size();
        }
    }
    for (int i = 0; i <= line; ++i) {
        for (int j = 0; j < words[i].size() - 1; ++j)
            printf("%-*s ", length[j], words[i][j].c_str());
        cout << words[i][words[i].size() - 1] << endl;
    }
    return 0;
}