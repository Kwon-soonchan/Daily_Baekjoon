// 1920번 수 찾기  -> 이진탐색
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int M;
		cin >> M;

		if (binary_search(v.begin(), v.end(), M)) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
}