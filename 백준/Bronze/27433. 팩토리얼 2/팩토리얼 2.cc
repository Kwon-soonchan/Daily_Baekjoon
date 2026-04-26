#include<iostream>
using namespace std;

long long factorial(int n) {
	if (n == 1) {
		return 1;
	}

	return factorial(n - 1) * n;
}

int main() {
	int n;
	cin >> n;

	if (n == 0) {
		cout << 1 << "\n";
		return 0;
	}

	long long result = factorial(n);

	cout << result << "\n";
}