#include<iostream>
#include<string>
using namespace std;

int main() {

	while (true) {
		int big = 0;
		int small = 0;
		int num = 0;
		int space = 0;
		string s;
		getline(cin, s);
		if (s == "") break;

		for (char c : s) {
			if (c >= 'A' && c <= 'Z') {
				big++;
			} else if (c >= 'a' && c <= 'z') {
				small++;
			} else if (c >= '0' && c <= '9') {
				num++;
			} else if (c == ' ') {
				space++;
			}
		}
		cout << small << " " << big << " " << num << " " << space << endl;
	}
}