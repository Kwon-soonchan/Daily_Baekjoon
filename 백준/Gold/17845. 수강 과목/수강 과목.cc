// 17845번 수강 과목
#include<iostream>
#include<algorithm>
using namespace std;

int dp[1001][10001];
int W[1001];
int V[1001];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= k; i++) {
		cin >> V[i] >> W[i];
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			if (j < W[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			}
		}
	}
	cout << dp[k][n];
}