#include<iostream>
using namespace std;

int main() {
	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;

	bool check = true;
	for (int i = n0; i <= 100; i++) {
		if (a1 * i + a0 > c * i) {
			check = false;
			break;
		}
	}
	if (check) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}