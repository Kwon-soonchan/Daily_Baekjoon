#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;

	while (cin >> a >> b >> c) {
		if (a == 0 && b == 0 && c == 0) {
			return 0;
		}
		else if (a + b <= c || b + c <= a || a + c <= b) {
			cout << "Invalid" << endl;
			continue;
		}
		if (a == b && b == c) {
			cout << "Equilateral" << endl;
		}
		else if (a == b || a == c || b == c) {
			cout << "Isosceles" << endl;
		}
		else {
			cout << "Scalene" << endl;
		}
	}

}