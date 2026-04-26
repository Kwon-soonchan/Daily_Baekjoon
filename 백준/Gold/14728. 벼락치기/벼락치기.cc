// 14728번 벼락치기
#include<iostream>
using namespace std;

int dp[101][10001];
int w[101];
int v[101];

int main() {
	int n, t;
	cin >> n >> t;

	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= t; j++) {
			if (j < w[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}
	}
	cout << dp[n][t];
}