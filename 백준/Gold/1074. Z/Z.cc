#include<iostream>
#include<cmath>
using namespace std;

int recursion(int n, int r, int c) {
	if (n == 0) {
		return 0;
	}

	int half = pow(2, n) / 2;
	int area = half * half;

	if (r < half) {
		// 1번
		if (c < half) {
			return recursion(n - 1, r, c);
		}
		// 2번
		else {
			return area + recursion(n - 1, r, c - half);
		}
	}
	else {
		// 3번
		if (c < half) {
			return 2*area + recursion(n - 1, r - half, c);
		}
		// 4번
		else {
			return 3*area + recursion(n - 1, r - half, c - half);
		}
	}
}

int main() {
	int n, r, c;
	cin >> n >> r >> c;

	cout << recursion(n, r, c);
}