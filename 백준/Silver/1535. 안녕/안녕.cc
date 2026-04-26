// 1535번 안녕
#include<iostream>
#include<algorithm>
using namespace std;

int dp[20][100];
int W[20];
int V[20];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> W[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> V[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 99; j++) {
			if (j < W[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			}
		}
	}
	cout << dp[n][99];
}