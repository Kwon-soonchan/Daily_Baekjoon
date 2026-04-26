#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m, k, x, y, i, j, w;
	int sum = 0;
	cin >> n >> m;
	vector <vector <int>> v;
	vector <int> v2;

	for (int a = 0; a < n; a++) {
		for (int b = 0; b < m; b++) {
			cin >> w;
			v2.push_back(w);
		}
		v.push_back(v2);
		v2.clear();
	}

	cin >> k;
	for (int c = 0; c < k; c++) {
		cin >> i >> j >> x >> y;
		for (int a = (j-1); a <= (y-1); a++) {
			for (int b = (i-1); b <= (x-1); b++) {
				sum += v[b][a];
			}
		}
		cout << sum << '\n';
		sum = 0;
	}
}