#include<iostream>
using namespace std;

long long dp[80];

int main() {
	int n;
	cin >> n;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 5;

	for (int i = 5; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	long long doole = 0;

	if (n == 1) {
		doole = 4;
	}
	else {
		doole = dp[n] * 2 + dp[n - 1] * 2;
	}

	cout << doole << endl;
}