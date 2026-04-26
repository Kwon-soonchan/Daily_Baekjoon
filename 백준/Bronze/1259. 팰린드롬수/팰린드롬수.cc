#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	while (true) {
		int count = 0;
		cin >> s;

		if (s == "0") {
			break;
		}
		else if (s.size() % 2 == 1) {
			for (int i = 0; i < ((s.size() - 1) / 2); i++) {
				if (s[i] == s[((s.size()-1)-i)])
					count++;
			}
			if (count == (s.size() - 1) / 2) {
				cout << "yes" << '\n';
			}
			else {
				cout << "no" << '\n';
			}
		}
		else if (s.size() % 2 == 0) {
			for (int j = 0; j < (s.size() / 2); j++) {
				if (s[j] == s[((s.size() - 1) - j)])
					count++;
			}
			if (count == (s.size() / 2)) {
				cout << "yes" << '\n';
			}
			else {
				cout << "no" << '\n';
			}
		}
		else {
			cout << "no" << '\n';
		}
	}
}