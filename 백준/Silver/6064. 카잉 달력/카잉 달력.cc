#include<iostream>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		int lcm = m * n / gcd(m, n);
		bool flag = false;

		for (int i = x; i <= lcm; i += m) {
			if ((i - y) % n == 0) {
				cout << i << endl;
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << -1 << endl;
		}
	}
}