// 12904번 A와 B
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s, t;
	cin >> s;
	cin >> t;

	while (t.length() > s.length()) {
		if (t.back() == 'A') {
			t.pop_back();
		}
		else if (t.back() == 'B') {
			t.pop_back();
			reverse(t.begin(), t.end());
		}
	}

	if (s == t) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}