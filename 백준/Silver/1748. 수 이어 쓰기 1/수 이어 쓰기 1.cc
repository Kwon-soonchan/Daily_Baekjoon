#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int len = 0;
	int digits = 1;
	int start = 1;

	while (start * 10 <= n) {
		len += (start * 10 - start) * digits;
		start *= 10;
		digits++;
	}
	len += (n - start + 1) * digits;

	cout << len << endl;
}