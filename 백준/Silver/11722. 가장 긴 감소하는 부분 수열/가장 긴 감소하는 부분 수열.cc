// 11722번 가장 긴 감소하는 부분 수열
#include<iostream>
#include<cmath>
using namespace std;

int dp[1001];
int arr[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		
		dp[i] = 1;
		arr[i] = a;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int result = 0;

	for (int i = 0; i < n; i++) {
		result = max(result, dp[i]);
	}

	cout << result;
}