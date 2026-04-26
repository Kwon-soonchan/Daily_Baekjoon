// 21964번 선린인터넷고등학교 교가
#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;

	bool check = false;

	for (char c : s) {
		if (c == ' ') {
			check = false;
			break;
		}
		else {
			check = true;
		}
	}

	if (check) {
		for (int i = s.length() - 5; i < n; i++) {
			cout << s[i];
		}
	}
}