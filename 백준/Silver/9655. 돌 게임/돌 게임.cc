#include<iostream>
using namespace std;

bool dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	dp[0] = false;
	dp[1] = true;
	dp[2] = false;

	for (int i = 3; i <= n; i++) {
		if (!dp[i - 1] || !dp[i - 3]) {
			dp[i] = true;
		}
		else {
			dp[i] = false;
		}
	}

	if (dp[n]) {
		cout << "SK" << endl;
	}
	else {
		cout << "CY" << endl;
	}
}