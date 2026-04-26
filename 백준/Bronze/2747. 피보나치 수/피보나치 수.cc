#include <iostream>
using namespace std;

int a[45] = { 0, };
int fibonachi(int n) {
	if (n <= 1) {
		return n;
	}
	if (a[n] > 0) {
		return a[n];
	}
	a[n] = fibonachi(n - 1) + fibonachi(n - 2);
	return a[n];
}

int main() {
	int n;
	cin >> n;
	cout << fibonachi(n);
}