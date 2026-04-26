#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n + 1);
	vector<int> dp(n + 2, 0);

	for (int i = 1; i <= n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	for (int i = n; i > 0; i--) {
		int t = v[i].first;
		int m = v[i].second;

		if (i + t <= n + 1) {
			dp[i] = max(dp[i + 1], m + dp[i + t]);
		}
		else {
			dp[i] = dp[i + 1];
		}
	}

	cout << dp[1];
}