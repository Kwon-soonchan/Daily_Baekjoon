#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int a, m, s;

double r(int a, int m, int& s) {
	double val = (s % m) / (double)m;
	s = (a * s + 1) % m;
	return val;
}

int main() {
	cin >> a >> m >> s;
	cin.ignore();

	string line;
	while (getline(cin, line)) {
		for (char c : line) {
			if (c >= ' ' && c <= '~') {
				int randomV = static_cast<int>(ceil(95 - r(a, m, s) * 95));
				int temp = ((static_cast<int>(c) - 32 - randomV + 95) % 95) + 32;
				cout << static_cast<char>(temp);
			}
			else {
				cout << c;
			}
		}
		cout << "\n";
	}
}