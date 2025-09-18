#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}

	int max_x = -2e9, max_y = -2e9;
	int min_x = 2e9, min_y = 2e9;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (max_x < x) {
			max_x = x;
		}
		if (min_x > x) {
			min_x = x;
		}
		if (max_y < y) {
			max_y = y;
		}
		if (min_y > y) {
			min_y = y;
		}
	}
	long long rec = abs(max_x - min_x) * abs(max_y - min_y);

	cout << rec << endl;
}