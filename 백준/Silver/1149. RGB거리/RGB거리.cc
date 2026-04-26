#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, r, g, b;
	cin >> n;

	vector<int> red(n), green(n), blue(n);

	for (int i = 0; i < n; i++) {
		cin >> r >> g >> b;
		if (i == 0) {
			red[i] = r;
			green[i] = g;
			blue[i] = b;
		}
		else {
			red[i] = min(green[i - 1], blue[i - 1]) + r;
			green[i] = min(red[i - 1], blue[i - 1]) + g;
			blue[i] = min(red[i - 1], green[i - 1]) + b;
		}
	}
	int result = min(red[n - 1], min(green[n - 1], blue[n - 1]));
	cout << result << endl;
}