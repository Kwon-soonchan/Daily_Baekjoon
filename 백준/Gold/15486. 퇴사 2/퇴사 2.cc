#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int dp[1500001];
vector<pair<int, int>> v(1500001);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	for (int i = n - 1; i >= 0; i--) {
		if (i + v[i].first <= n) {
			dp[i] = max(dp[i + v[i].first] + v[i].second, dp[i + 1]);
		}
		else
		{
			dp[i] = dp[i + 1];
		}
	}

	cout << dp[0] << endl;
}