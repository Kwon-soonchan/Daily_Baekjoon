#include<iostream>
#include<vector>
using namespace std;

int dp[1001];

int main() {
	int n;
	cin >> n;
	vector<vector<int>> v(2, vector<int>(n));

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	}

	cout << dp[n];
}