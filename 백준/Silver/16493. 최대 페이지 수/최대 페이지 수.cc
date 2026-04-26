#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dp[21][201];
int T[21];
int P[21];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> T[i] >> P[i];
    }

    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = 0;
        }
    }
    
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (j < T[i]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-T[i]] + P[i]);
            }
        }
    }
    
    cout << dp[M][N];
}