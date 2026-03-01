#include<iostream>
using namespace std;

int main() {

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int k;
		cin >> k;

		int sum_total = 0;

		for (int j = 1; j <= k; j++) {
			int sum_k = 0;

			for (int jj = 1; jj <= j + 1; jj++) {
				sum_k += jj;
			}

			sum_total += j * sum_k;
		}

		cout << sum_total << "\n";
	}
}