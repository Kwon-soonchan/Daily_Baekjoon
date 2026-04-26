// 11047번 동전 0 (그리디)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.rbegin(), v.rend());

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (k >= v[i]) {
			cnt += k / v[i];
			k %= v[i];
		}
	}

	cout << cnt;
}