#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
// #define DEBUG
#define PREFIX "     "

void parse(const string& all, string& name, string& mta) {
    int pos = all.find('@');
    name = all.substr(0, pos);
    mta = all.substr(pos + 1);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    set<string> mtas;
    string line;
    //输入所有的MTA
    while (cin >> line && line != "*") {
        string name, member;
        int num;
        cin >> name >> num;
        while (num--) {
            cin >> member;
            mtas.insert(member + "@" + name);
        }
    }
    getchar();
    //对于每一封邮件
    while (getline(cin, line) && line != "*") {
        stringstream ss(line);
        //发件人
        string send, sendName, sendMta;
        ss >> send;
        parse(send, sendName, sendMta);
        map<string, vector<string>> receivers;
        vector<string> receMtas;
        set<string> rep;
        string rece, receName, receMta;
        //收件人
        while (ss >> rece) {
            if (rep.count(rece))
                continue;
            rep.insert(rece);
            parse(rece, receName, receMta);
            if (!receivers.count(receMta))
                receMtas.push_back(receMta);
            receivers[receMta].push_back(rece);
        }
        getline(cin, line);
        vector<string> data;
        //内容
        while (getline(cin, line) && line != "*")
            data.push_back(line);
        //交互
        for (vector<string>::iterator it = receMtas.begin(); it != receMtas.end(); ++it) {
            cout << "Connection between " << sendMta << " and " << *it << endl;
            cout << PREFIX << "HELO " << sendMta << endl;
            cout << PREFIX << "250" << endl;
            cout << PREFIX << "MAIL FROM:<" << send << ">" << endl;
            cout << PREFIX << "250" << endl;
            bool flag = false;
            for (vector<string>::iterator vit = receivers[*it].begin(); vit != receivers[*it].end(); ++vit) {
                cout << PREFIX << "RCPT TO:<" << *vit << ">" << endl;
                if (mtas.count(*vit)) {
                    flag = true;
                    cout << PREFIX << "250" << endl;
                } else
                    cout << PREFIX << "550" << endl;
                ;
            }
            if (flag) {
                cout << PREFIX << "DATA" << endl;
                cout << PREFIX << "354" << endl;
                for (vector<string>::iterator vit = data.begin(); vit != data.end(); ++vit)
                    cout << PREFIX << "" << *vit << endl;
                cout << PREFIX << "." << endl;
                cout << PREFIX << "250" << endl;
            }
            cout << PREFIX << "QUIT" << endl;
            cout << PREFIX << "221" << endl;
        }
    }
    return 0;
}