// 2579번 계단 오르기
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int dp[300];
	dp[0] = v[0];
	dp[1] = v[0] + v[1];
	dp[2] = max(v[0] + v[2], v[1] + v[2]);

	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]);
	}

	cout << dp[n-1];
}