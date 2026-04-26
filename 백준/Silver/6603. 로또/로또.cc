#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<int> v(n);
		vector<int> v2(n, 1);
		
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}


		sort(v.begin(), v.end());
		for (int i = 0; i < 6; i++) {
			v2[i] = 0;
		}

		do {
			for (int i = 0; i < n; i++) {
				if (v2[i] == 0) {
					cout << v[i] << " ";
				}
			}
			cout << "\n";
		} while (next_permutation(v2.begin(), v2.end()));

		cout << "\n";
	}
}