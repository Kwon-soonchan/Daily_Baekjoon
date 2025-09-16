#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 1) {
		return 0;
	}

	int r = 2;
	while (n > 1) {
		if (n % r == 0) {
			cout << r << endl;
			n /= r;
		}
		else {
			r++;
		}
	}
}