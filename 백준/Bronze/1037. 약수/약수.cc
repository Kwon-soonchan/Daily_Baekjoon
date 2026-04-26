#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	int sum = 0;
	vector <int> v;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m;
		v.push_back(m);
	}
	sort(v.begin(), v.end());
	if (v.size() == 1) {
		sum = v[0] * v[0];
	}
	else {
		sum = v[0] * v[v.size() - 1];
	}
	cout << sum;
}