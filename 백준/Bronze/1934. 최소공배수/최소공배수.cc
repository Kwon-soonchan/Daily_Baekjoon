#include<iostream>
using namespace std;

int gcd(int a, int b) {
	if (a == 0) {
		return b;
	}
	return gcd(b%a, a);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int a, b, lcm;
		cin >> a >> b;

		if (a < b) {
			lcm = (a * b) / gcd(a, b);
		}
		else {
			lcm = (a * b) / gcd(b, a);
		}
		cout << lcm << "\n";
	}
}