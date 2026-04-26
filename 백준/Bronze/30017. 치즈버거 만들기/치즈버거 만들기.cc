#include<iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	if (b >= a) {
		b = a - 1;
	}
	else {
		a = b + 1;
	}
	cout << a + b;
}