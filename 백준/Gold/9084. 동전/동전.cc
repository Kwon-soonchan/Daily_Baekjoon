// 9084번 동전
#include<iostream>
#include<algorithm>
using namespace std;

int dp[10001];
int coin[21];

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		fill(dp, dp + 10001, 0);
		fill(coin, coin + 21, 0);

		int n;
		cin >> n;

		for (int j = 0; j < n; j++) {
			cin >> coin[j];
		}
		int cost;
		cin >> cost;

		dp[0] = 1;

		for (int j = 0; j < n; j++) {
			for (int k = coin[j]; k <= cost; k++) {
				dp[k] += dp[k - coin[j]];
			}
		}
		cout << dp[cost] << '\n';

	}
}