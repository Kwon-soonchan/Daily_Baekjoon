// 2446번 별 찍기 - 9
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i <= (2*n - 1) / 2; i++) {
		for (int j = 0; j < i; j++) {
			cout << ' ';
		}
		for (int j = 0; j < (2*n - 1 - (2 * i)); j++) {
			cout << '*';
		}
		cout << '\n';
	}

	for (int i = 0; i < ((2 * n - 1) / 2); i++) {
		for (int j = ((2 * n - 1) / 2) - (i+1); j > 0; j--) {
			cout << ' ';
		}
		for (int j = 0; j < (2 * (i + 2)) - 1; j++) {
			cout << '*';
		}
		cout << '\n';
	}
}