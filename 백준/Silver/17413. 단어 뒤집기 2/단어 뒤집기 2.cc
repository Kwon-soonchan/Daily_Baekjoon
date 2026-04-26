#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    string result;
    string word;
    bool tag = false;

    for (char c : s) {
        if (c == '<') {
            reverse(word.begin(), word.end());
            result += word;
            word.clear();
            tag = true;
            result += c;
        }
        else if (c == '>') {
            tag = false;
            result += c;
        }
        else if (tag) {
            result += c;
        }
        else {
            if (c == ' ') {
                reverse(word.begin(), word.end());
                result += word;
                result += ' ';
                word.clear();
            }
            else {
                word += c;
            }
        }
    }

    if (!word.empty()) {
        reverse(word.begin(), word.end());
        result += word;
    }

    cout << result << endl;
}