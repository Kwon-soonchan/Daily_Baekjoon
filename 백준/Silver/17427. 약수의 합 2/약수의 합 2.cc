#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	long long sum = 0;

	// O(N^2) solution
	/*for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			if ((n-i) % j == 0) {
				sum += j;
			}
		}
	}*/

	// O(N) solution
	for(int i = 1; i <= n; i++) {
		sum += n / i * i;
	}

	cout << sum << endl;
}