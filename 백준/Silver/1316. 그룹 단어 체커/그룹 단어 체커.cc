// 1316번 그룹 단어 체커
#include<iostream>
#include<string>
#include<set>
using namespace std;

int main() {
    int n;
    int count = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        bool check = true;
        set<char> seen;

        for (int j = 0; j < s.length(); j++) {
            if (j > 0 && s[j] != s[j - 1]) {
                if (seen.find(s[j]) != seen.end()) {
                    check = false;
                    break;
                }
            }
            seen.insert(s[j]);
        }

        if (check) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}