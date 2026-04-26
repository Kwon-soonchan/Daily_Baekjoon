// 31861번 비밀번호 만들기
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> dp(M + 1, vector<int>(26, 0));

    // 첫 번째 자리에서는 모든 알파벳이 가능
    for (int i = 0; i < 26; i++) {
        dp[1][i] = 1;
    }

    // 두 번째 자리부터 M번째 자리까지 계산
    for (int i = 2; i <= M; i++) {
        for (int j = 0; j < 26; j++) {
            // 이전 자리에서 가능한 알파벳들의 개수를 누적
            for (int k = 0; k < 26; k++) {
                if (abs(j - k) >= N) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
        }
    }

    int answer = 0;
    // 마지막 자리에서 가능한 알파벳들의 개수를 모두 더함
    for (int i = 0; i < 26; i++) {
        answer = (answer + dp[M][i]) % MOD;
    }

    cout << answer << endl;

    return 0;
}