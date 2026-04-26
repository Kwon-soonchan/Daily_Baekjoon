#include<iostream>
#include<string>
using namespace std;

char number[36] = { '0', '1','2','3','4','5','6','7','8','9', 'A', 'B', 'C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

int main() {
	int n, b;
	cin >> n >> b;

	string s = "";
	while (n > 0) {
		s += number[(n % b)];
		n /= b;
	}

	for (int i = s.length() - 1; i >= 0; i--) {
		cout << s[i];
	}
}