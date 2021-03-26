#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef enum { SHELVE, BORROWED, RETURED } BStatus;
#define DEBUG

struct Book {
    string name;
    string author;
    BStatus status = SHELVE;
    bool operator<(const Book& b) const { return author < b.author || author == b.author && name < b.name; }
};

vector<Book> books;
map<string, int> indices;

void addBook(string& bookInfo) {
    int pos1 = bookInfo.find("\""), pos2 = bookInfo.find("by");
    Book book;
    book.name = bookInfo.substr(pos1, pos2 - pos1 - 1);
    book.author = bookInfo.substr(pos2 + 3);
    books.push_back(book);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    string bookInfo;
    while (getline(cin, bookInfo) && bookInfo != "END")
        addBook(bookInfo);
    sort(books.begin(), books.end());
    for (int i = 0; i < books.size(); ++i)
        indices[books[i].name] = i;
    string command;
    while (getline(cin, command) && command != "END") {
        if (command[0] == 'B')
            books[indices[command.substr(7)]].status = BORROWED;
        else if (command[0] == 'R')
            books[indices[command.substr(7)]].status = RETURED;
        else {
            string preBook = "";
            for (int i = 0; i < books.size(); ++i) {
                switch (books[i].status) {
                case SHELVE:
                    preBook = books[i].name;
                    break;
                case RETURED:
                    if (preBook == "")
                        cout << "Put " << books[i].name << " first" << endl;
                    else
                        cout << "Put " << books[i].name << " after " << preBook << endl;
                    books[i].status = SHELVE;
                    preBook = books[i].name;
                    break;
                default:
                    break;
                }
            }
        }
    }
    puts("END");
    return 0;
}