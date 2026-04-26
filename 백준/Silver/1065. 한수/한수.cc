// 1065번 한수
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int count = 0;

	for (int i = 1; i <= n; i++) {
		if (i < 100) {
			count++;
		}
		else {
			int a, b, c;
			a = i / 100;
			b = (i % 100) / 10;
			c = (i % 100) % 10;

			if ((b - a) == (c - b)) {
				count++;
			}
		}
	}

	cout << count;
}
