#include<iostream>
using namespace std;

int dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int cnt = 0;

	if (n == 1 || n == 3) {
		cout << -1;
		return 0;
	}
	else {
		while (n > 0) {
			if (n % 5 != 0) {
				n -= 2;
				cnt++;
			}
			else {
				cnt += n / 5;
				break;
			}
		}
	}

	cout << cnt << endl;
	return 0;
}	