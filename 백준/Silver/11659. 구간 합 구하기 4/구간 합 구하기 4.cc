#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	
    int n, m, i, j;
	int sum = 0;
	int num[99'999] = { 0, };
	int list[99'999] = { 0, };
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
		sum += num[i];
		list[i] = sum;
	}
	
	for (int k = 0; k < m; k++) {
		cin >> i >> j;
		if (i == j) {
			cout << num[i - 1];
		}
		else if (i == 1) {
			cout << list[j - 1];
		}
		else {
			cout << (list[j - 1] - list[i - 2]);
		}
		cout << '\n';
	}
}