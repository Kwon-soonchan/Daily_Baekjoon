// 25175번 두~~부 두부 두부
#include<iostream>
#include<cstdlib>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	int a = abs(m + (k - 3));

	if ((m + k - 3) >= 1) {
		if (a % n == 0) {
			cout << n;
		}
		else {
			cout << a % n;
		}
	}
	else {
		cout << n - (a % n);
	}
}
