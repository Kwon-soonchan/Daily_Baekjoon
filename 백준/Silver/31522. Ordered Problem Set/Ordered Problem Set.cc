#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n + 1);  // 1-based
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	bool found = false;
	for (int k = 2; k <= n; k++) {
		if (n % k != 0) continue;

		int len = n / k;
		bool valid = true;
		int prev_max = -1;

		for (int i = 0; i < k; i++) {
			int start = i * len + 1;
			int end = (i + 1) * len;
			int cur_min = v[start];
			int cur_max = v[start];

			for (int j = start + 1; j <= end; j++) {
				cur_min = min(cur_min, v[j]);
				cur_max = max(cur_max, v[j]);
			}

			if (prev_max >= cur_min) {
				valid = false;
				break;
			}
			prev_max = cur_max;
		}

		if (valid) {
			cout << k << "\n";
			found = true;
		}
	}
	if (!found) {
		cout << -1 << "\n";
	}
	return 0;
}
