// 1106번 호텔
#include<iostream>
#include<algorithm>
using namespace std;

int dp[2001];
int w[21];
int v[21];

int main() {
	int c, n;
	cin >> c >> n;

	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	fill(dp + 1, dp + 2001, 2e9);

	for (int i = 1; i <= n; i++) {
		for (int j = v[i]; j <= 2000; j++) {
			dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
		}
	}
	int result = 2e9;
	for (int i = c; i <= 2000; i++) {
		result = min(result, dp[i]);
	}

	cout << result;
}