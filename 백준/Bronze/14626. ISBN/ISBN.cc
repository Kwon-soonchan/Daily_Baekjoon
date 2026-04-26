#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;

	int sum = 0;
	int list[10] = { 0, };

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '*') {
			if (i % 2 == 0) {
				for (int j = 0; j < 10; j++) {
					list[j] += j;
				}
			}
			else {
				for (int j = 0; j < 10; j++) {
					list[j] += j * 3;
				}
			}
		}
		else {
			if (i % 2 == 0) {
				sum += s[i] - '0';
			}
			else {
				sum += (s[i] - '0') * 3;
			}
		}
	}
	for (int j = 0; j < 10; j++) {
		list[j] += sum;

		if (list[j] % 10 == 0) {
			cout << j;
		}
	}
}