#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define DEBUG

int articleNum, queryNum;
vector<string> articles[105];
map<string, set<pair<int, int>>> did;

void handleWord(string& word, vector<string>& words) {
    int startPos = 0, endPos = word.size() - 1;
    while (!isalpha(word[startPos]) && startPos <= endPos)
        ++startPos;
    while (!isalpha(word[endPos]) && startPos <= endPos)
        --endPos;
    if (startPos > endPos)
        return;
    word = word.substr(startPos, endPos - startPos + 1);
    for (string::iterator it = word.begin(); it != word.end(); ++it)
        *it = tolower(*it);
    int pos = word.find('-');
    if (pos != -1) {
        words.push_back(word.substr(0, pos));
        words.push_back(word.substr(pos + 1));
    } else
        words.push_back(word);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &articleNum);
    string oneLine, word;
    int lineNum;
    //每篇文章
    for (int i = 0; i < articleNum; ++i) {
        lineNum = -1;
        //每一行
        while (getline(cin, oneLine) && oneLine != "**********") {
            ++lineNum;
            articles[i].push_back(oneLine);
            stringstream ss(oneLine);
            while (ss >> word) {
                vector<string> words;
                handleWord(word, words);
                for (vector<string>::iterator it = words.begin(); it != words.end(); ++it) {
                    if (did.count(*it))
                        did[*it].insert(make_pair(i, lineNum));
                    else {
                        set<pair<int, int>> s;
                        s.insert(make_pair(i, lineNum));
                        did[*it] = s;
                    }
                }
            }
        }
    }
    scanf("%d", &queryNum);
    string query;
    getline(cin, query);
    int pos;
    while (queryNum--) {
        getline(cin, query);
        if ((pos = query.find("NOT")) != -1) {
            set<pair<int, int>> s;
            string s1 = query.substr(pos + 4);
            if (did.count(s1))
                s = did[s1];
            int article = -1;
            bool first = true;
            for (set<pair<int, int>>::iterator it = s.begin(); it != s.end(); ++it)
                if (it->first != article) {
                    for (int i = article + 1; i < it->first; ++i) {
                        if (!first)
                            cout << "----------" << endl;
                        for (vector<string>::iterator vit = articles[i].begin(); vit != articles[i].end(); ++vit)
                            cout << *vit << endl;
                        first=false;
                    }
                    article = it->first;
                }
            for (int i = article + 1; i < articleNum; ++i) {
                if (!first)
                    cout << "----------" << endl;
                for (vector<string>::iterator vit = articles[i].begin(); vit != articles[i].end(); ++vit)
                    cout << *vit << endl;
                first=false;
            }
            cout << "==========" << endl;
        } else {
            set<pair<int, int>> s;
            if ((pos = query.find("OR")) != -1) {
                string s1 = query.substr(0, pos - 1), s2 = query.substr(pos + 3);
                if (did.count(s1) && did.count(s2))
                    set_union(did[s1].begin(), did[s1].end(), did[s2].begin(), did[s2].end(), inserter(s, s.begin()));
                else if (did.count(s1))
                    s = did[s1];
                else if (did.count(s2))
                    s = did[s2];
            } else if ((pos = query.find("AND")) != -1) {
                string s1 = query.substr(0, pos - 1), s2 = query.substr(pos + 4);
                if (did.count(s1) && did.count(s2)) {
                    set<pair<int, int>>::iterator it1 = did[s1].begin();
                    set<pair<int, int>>::iterator it2 = did[s2].begin();
                    while (it1 != did[s1].end() && it2 != did[s2].end()) {
                        if (it1->first < it2->first) {
                            while (it1 != did[s1].end() && it1->first < it2->first)
                                ++it1;
                            if (it1 == did[s1].end())
                                break;
                        }
                        if (it1->first > it2->first) {
                            while (it2 != did[s2].end() && it1->first > it2->first)
                                ++it2;
                            if (it2 == did[s2].end())
                                break;
                        }
                        int article = it1->first;
                        while (it1 != did[s1].end() && it1->first == article) {
                            s.insert(*it1);
                            ++it1;
                        }
                        while (it2 != did[s2].end() && it2->first == article) {
                            s.insert(*it2);
                            ++it2;
                        }
                    }
                }
            } else if (did.count(query))
                s = did[query];
            if (s.size() == 0) {
                cout << "Sorry, I found nothing." << endl;
                cout << "==========" << endl;
                continue;
            }
            int article = -1;
            for (set<pair<int, int>>::iterator it = s.begin(); it != s.end(); ++it) {
                if (article != -1 && article != it->first)
                    cout << "----------" << endl;
                cout << articles[it->first][it->second] << endl;
                article = it->first;
            }
            cout << "==========" << endl;
        }
    }
    return 0;
}