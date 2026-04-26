// 1522번 문자열 교환
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    int a_cnt = 0;
    int min_change = n;

    for (char c : s) {
        if (c == 'a') a_cnt++;
    }

    s += s;

    for (int i = 0; i < n; i++) {
        int b_cnt = 0;
        for (int j = i; j < i + a_cnt; j++) {
            if (s[j] == 'b') b_cnt++;
        }
        min_change = min(min_change, b_cnt);
    }

    cout << min_change << endl;
    return 0;
}