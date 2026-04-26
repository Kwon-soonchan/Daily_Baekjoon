#include<iostream>
using namespace std;

int main() {
	int a, b, n;
	cin >> a >> b >> n;

	a %= b;

	int digit = 0;

	while (n--) {
		a *= 10;
		digit = a / b;
		a %= b;
	}
	cout << digit << endl;
}  