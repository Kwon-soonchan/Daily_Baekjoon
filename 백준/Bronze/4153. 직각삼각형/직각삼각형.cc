// 4153번 직각삼각형
#include<iostream>
using namespace std;

int main() {
	while (true) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) {
			break;
		}
		if ((a * a) + (b * b) == (c * c) || (b * b) + (c * c) == (a * a) || (a * a) + (c * c) == (b * b)) {
			cout << "right" << '\n';
		}
		else {
			cout << "wrong" << '\n';
		}
	}
}