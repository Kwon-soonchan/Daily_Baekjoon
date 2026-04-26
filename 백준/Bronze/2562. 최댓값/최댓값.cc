#include <iostream>
using namespace std;

int main() {
	int a = 0;
	int b = 0;
	int num[9];
	for (int i = 0; i < 9; i++) {
		cin >> a;
		num[i] = a;
		b = max(a, b);
	}
	for (int j = 0; j < 9; j++) {
		if (num[j] == b) {
			cout << b << '\n' << j + 1;
		}
	}
}