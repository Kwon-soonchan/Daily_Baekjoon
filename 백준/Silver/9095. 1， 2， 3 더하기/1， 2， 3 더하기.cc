#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int dp[12];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;


	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		for (int j = 3; j <= num; j++) {
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		}
		cout << dp[num] << "\n";
	}
}