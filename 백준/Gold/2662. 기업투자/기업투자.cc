// 2662번 기업투자
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[301][21];
int profit[21][301];
int investment[301][21];

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int amount;
        cin >> amount;
        for (int j = 1; j <= M; j++) {
            cin >> profit[j][i];
        }
    }

    for (int j = 1; j <= M; j++) {
        for (int i = 1; i <= N; i++) {
            dp[i][j] = dp[i][j - 1];
            for (int k = 1; k <= i; k++) {
                if (dp[i][j] < dp[i - k][j - 1] + profit[j][k]) {
                    dp[i][j] = dp[i - k][j - 1] + profit[j][k];
                    investment[i][j] = k;
                }
            }
        }
    }

    cout << dp[N][M] << endl;

    vector<int> result(M + 1, 0);
    int remain = N;
    for (int j = M; j >= 1; j--) {
        result[j] = investment[remain][j];
        remain -= result[j];
    }

    for (int i = 1; i <= M; i++) {
        cout << result[i] << " ";
    }
}