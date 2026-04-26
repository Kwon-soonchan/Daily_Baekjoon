#include <iostream>
using namespace std;

int main() {
	long long n, m;
	long long sum = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m;
			sum += m;
		}
	}
	cout << sum;
}