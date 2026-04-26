// 9324번 진짜 메시지
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        vector<int> count(26, 0);
        bool is_fake = false;

        for (int j = 0; j < s.length(); j++) {
            count[s[j] - 'A']++;

            if (count[s[j] - 'A'] == 3) {
                if (j + 1 < s.length() && s[j] == s[j + 1]) {
                    count[s[j] - 'A'] = 0;
                    j++;
                }
                else {
                    is_fake = true;
                    break;
                }
            }
        }

        cout << (is_fake ? "FAKE" : "OK") << '\n';
    }
    return 0;
}