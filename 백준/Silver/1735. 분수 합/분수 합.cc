#include<iostream>
using namespace std;

int gcd(int a, int b) {
	if (a == 0) {
		return b;
	}
	return gcd(b % a, a);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;

	int b = b1 * b2;
	int a = b1 * a2 + b2 * a1;

	int d = 0;
	if (a > b) {
		d = gcd(b, a);
	}
	else {
		d = gcd(a, b);
	}

	a = a / d;
	b = b / d;

	cout << a << " " << b << "\n";
}