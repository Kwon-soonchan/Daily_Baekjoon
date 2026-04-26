#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n, q, i, j, number;
	int sum = 0;
	vector <int> num;
	vector <int> list;
	cin >> n >> q;

	for (int k = 0; k < n; k++) {
		cin >> number;
		num.push_back(number);
	}
	sort(num.begin(), num.end());

	for (int k : num) {
		sum += k;
		list.push_back(sum);
	}

	for (int k = 0; k < q; k++) {
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