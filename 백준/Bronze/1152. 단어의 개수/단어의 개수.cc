#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    int wordCount = 0;
    bool inWord = false;

    for (char c : input) {
        // 단어의 시작을 나타내는 조건
        if (c != ' ' && !inWord) {
            inWord = true;
            wordCount++;
        }
        // 단어의 끝을 나타내는 조건
        else if (c == ' ' && inWord) {
            inWord = false;
        }
    }

    cout << wordCount << endl;

    return 0;
}