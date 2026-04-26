// 17208번 카우버거 알바생
#include<iostream>
using namespace std;

int dp[101][301][301];
int w[101];
int v[101];

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int l = 0; l <= k; l++) {
				if (j >= w[i] && l >= v[i]) {
					dp[i][j][l] = max(dp[i - 1][j][l], dp[i - 1][j - w[i]][l - v[i]] + 1);
				}
				else {
					dp[i][j][l] = dp[i - 1][j][l];
				}
			}
		}
	}
	cout << dp[n][m][k];
}