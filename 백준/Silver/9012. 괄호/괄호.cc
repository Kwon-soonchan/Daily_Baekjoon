// 9012번 괄호
#include<iostream>
#include<string>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;

		int balance = 0;
		bool valid = true;

		for (char c : s) {
			if (c == '(') {
				balance++;
			}
			else if (c == ')') {
				balance--;
			}

			if (balance < 0) {
				valid = false;
				break;
			}
		}

		if (balance == 0 && valid) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
}