#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n, m, i, j;
	int sum = 0;
	int num[100'000];
	int list[100'000];
	cin >> n;
	for (int k = 0; k < n; k++) {
		cin >> num[k];
		sum += num[k];
		list[k] = sum;
	}
	cin >> m;
	for (int k = 0; k < m; k++) {
		cin >> i >> j;
		
		if (i == j) {
			cout << num[i - 1];
		}
		else if (i == 1) {
			cout << list[j - 1];
		}
		else {
			cout << list[j - 1] - list[i - 2];
		}
		cout << '\n';
	}
}