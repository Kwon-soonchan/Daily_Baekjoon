#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<long long> dp(n + 2, 0);

	dp[0] = 1;
	dp[1] = 2;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n] - dp[n-1] << endl;
}