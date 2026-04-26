// 18917번 수열과 쿼리 38 --> solved.ac 배경 얻기용 문제
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	long long sum = 0;
	long long x = 0;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		if (a == 1) {
			int b;
			cin >> b;

			sum += b;
			x ^= b;
		}
		else if (a == 2) {
			int b;
			cin >> b;

			sum -= b;
			x ^= b;
		}
		else if (a == 3) {
			cout << sum << '\n';
		}
		else if (a == 4) {
			cout << x << '\n';
		}
	}
}