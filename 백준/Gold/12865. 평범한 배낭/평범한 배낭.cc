// 12865번 평범한 배낭
#include<iostream>
#include<algorithm>
using namespace std;

int dp[101][100'001];
int W[101];
int V[101];

int main() {
	int n, k;
	cin >> n >> k;

	for(int i = 1; i <= n; i++) {
		cin >> W[i] >> V[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j < W[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			}
		}
	}
	cout << dp[n][k];
}