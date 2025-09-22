#include<iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long cnt = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			cnt++;
		}
	}

	cout << cnt << endl << 2;
}
