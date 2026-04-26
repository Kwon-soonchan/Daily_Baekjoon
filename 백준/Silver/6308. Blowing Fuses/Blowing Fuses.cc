#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
	int n, m, c;
	int testcase = 0;


	while (true) {
		cin >> n >> m >> c;
		vector<pair<int, int>> N(n + 1, { 0, 0 });
		int sum = 0;
		int max_sum = 0;
		testcase++;

		if (n == 0 && m == 0 && c == 0) {
			break;
		}

		for (int i = 0; i < n; i++) {
			cin >> N[i + 1].second;
		}
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;

			if (N[x].first == 0) {
				N[x].first = 1;
				sum += N[x].second;
			}
			else {
				N[x].first = 0;
				sum -= N[x].second;
			}

			max_sum = max(sum, max_sum);
		}
		if (sum > c) {
			cout << "Sequence " << testcase << "\n" << "Fuse was blown.\n";
		}
		else {
			cout << "Sequence " << testcase << "\n" << "Fuse was not blown.\n"
				<< "Maximal power consumption was " << max_sum << " amperes.\n";
		}
		cout << "\n";
	}
}