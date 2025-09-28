#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;

bool is_prime(long long num) {
	if (num < 2) {
		return false;
	}

	for (long long i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		long long n;
		cin >> n;

		for (long long i = n; ; i++) {
			if (is_prime(i)) {
				cout << i << "\n";
				break;
			}
		}
	}
}