// 4781번 사탕 가게
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int dp[5001][10001];
int C[5001];
int P[5001];

int main() {
    cout << fixed << setprecision(2);

    while (true) {
        int n;
        float m;
        cin >> n >> m;
        if (n == 0 && m == 0.00) {
            break;
        }

        int m2int = (int)(m * 100 + 0.5);

        for (int i = 1; i <= n; i++) {
            float p;
            cin >> C[i] >> p;
            P[i] = (int)(p * 100 + 0.5);
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m2int; j++) {
                dp[i][j] = 0;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m2int; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= P[i]) {
                    dp[i][j] = max(dp[i][j], dp[i][j - P[i]] + C[i]);
                }
            }
        }

        cout << dp[n][m2int] << '\n';
    }

    return 0;
}