// 13423번 Three Dots
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int cnt = 0;

		vector<int> v(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < n-2; i++) {
			for (int j = i + 1; j < n-1; j++) {
				int low = j + 1;
				int high = n - 1;
				while (low <= high) {
					int mid = (low + high) / 2;
					int target = (2 * v[j]) - v[i];

					if (target == v[mid]) {
						cnt++;
						break;
					}
					if (target < v[mid]) {
						high = mid - 1;
					}
					else if (target > v[mid]) {
						low = mid + 1;
					}
				}
			}
		}
		cout << cnt << '\n';

	}
}