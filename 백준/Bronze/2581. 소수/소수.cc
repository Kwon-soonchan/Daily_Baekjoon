#include<iostream>
#include<vector>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;

	int sum = 0;
	vector<int> sosu;
	
	if (m == 1 && n == 1) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = m; i <= n; i++) {
		if (i < 2) {
			continue;
		}

		bool check = true;
		
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				check = false;
				break;
			}
		}
		if (check) {
			sosu.push_back(i);
			sum += i;
		}
	}

	if (!sosu.empty()) {
		cout << sum << endl << sosu[0] << endl;
	}
	else {
		cout << -1;
	}
}