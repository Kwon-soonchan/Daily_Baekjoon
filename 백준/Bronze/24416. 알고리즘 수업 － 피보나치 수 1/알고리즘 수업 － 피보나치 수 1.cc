#include<iostream>
using namespace std;

int cnt_recursion = 0;
int cnt_dp = 0;

int fib(int n) {
	if (n == 1 || n == 2) {
		cnt_recursion++;
		return 1;
	}
	else {
		return fib(n - 1) + fib(n - 2);
	}
}

int dp[41];

int main() {
	int n;
	cin >> n;

	fib(n);

	dp[1] = 1;
	dp[2] = 1;

	for(int i=3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		cnt_dp++;
	}

	cout << cnt_recursion << " " << cnt_dp << endl;
}