// 5995번 Bessie's Weight Problem
#include<iostream>
#include<algorithm>
using namespace std;

int dp[45001];
int W[501];

int main() {
	int h, n;
	cin >> h >> n;

	for (int i = 1; i <= n; i++) {
		cin >> W[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = h; j >= W[i]; j--) {
			dp[j] = max(dp[j], dp[j - W[i]] + W[i]);
		}
	}

	cout << dp[h];
}