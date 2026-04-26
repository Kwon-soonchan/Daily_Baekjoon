// 15831번 준표의 조약돌
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N, B, W;
    string s;
    cin >> N >> B >> W;
    cin >> s;

    int max_len = 0;
    int start = 0;
    int b_count = 0;
    int w_count = 0;

    for (int end = 0; end < N; end++) {
        if (s[end] == 'B') {
            b_count++;
        }
        else {
            w_count++;
        }

        while (b_count > B) {
            if (s[start] == 'B') {
                b_count--;
            }
            else {
                w_count--;
            }
            start++;
        }

        if (w_count >= W) {
            max_len = max(max_len, end - start + 1);
        }
    }

    cout << max_len;
}