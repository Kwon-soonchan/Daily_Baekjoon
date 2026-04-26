// 2444번 별 찍기 - 7
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = n - i; j > 0; j--) {
			cout << ' ';
		}
		for (int j = 0; j < 2 * i - 1; j++) {
			cout << '*';
		}
		cout << '\n';
	}

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < i; j++) {
			cout << ' ';
		}
		for (int j = 2 * (n - i) - 1; j > 0; j--) {
			cout << '*';
		}
		cout << '\n';
	}
}