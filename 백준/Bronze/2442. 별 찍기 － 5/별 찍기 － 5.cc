#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int k = n; k > i+1; k--) {
			cout << ' ';
		}
		for (int l = 0; l < i; l++) {
			cout << '*';
		}
		for (int j = 0; j < i+1; j++) {
			cout << '*';
		}
		cout << '\n';
	}
}