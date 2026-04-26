#include <iostream>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, q, cnt, num[100'001], list[100'001];

int main() {
	fastio;
	cin >> n;
	for (int k = 1; k <= n; k++) {
		cin >> num[k];
	}
	for (int k = 1; k <= n; k++) {
		if (num[k] > num[k + 1]) {
			cnt++;
		}
		list[k + 1] = cnt;
	}

	cin >> q;
	while (q--) {
		int i, j;
		cin >> i >> j;
		cout << list[j] - list[i] << '\n';
	}
}