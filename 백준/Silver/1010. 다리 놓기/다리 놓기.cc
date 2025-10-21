#include<iostream>
using namespace std;

int dp[31][31];

int comb(int n, int m) {
	if (m == 0 || n == m) {
		return 1;
	}
	if (dp[n][m]) {
		return dp[n][m];
	}
	return dp[n][m] = comb(n - 1, m - 1) + comb(n - 1, m);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n, m; 
		cin >> n >> m;

		cout << comb(m, n) << '\n';
	}
}