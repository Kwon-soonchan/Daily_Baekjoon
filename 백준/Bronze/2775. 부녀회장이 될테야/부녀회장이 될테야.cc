// 2775번 부녀회장이 될테야
#include<iostream>
using namespace std;

int arr[15][15];

int house(int k,int n) {
	for (int i = 0; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 0) {
				arr[i][j] = j;
			}
			else {
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			}
		}
	}

	return arr[k][n];
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int k, n;
		cin >> k >> n;

		cout << house(k, n) << '\n';
	}
}