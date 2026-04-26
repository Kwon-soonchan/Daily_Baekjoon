#include<iostream>
#include<string>
using namespace std;

int cnt = 0;

int recursion(const string& s, int l, int r) {
	if (l >= r) {
		cnt++;
		return 1;
	}
	else if (s[l] != s[r]) {
		cnt++;
		return 0;
	}
	else {
		cnt++;
		return recursion(s, l + 1, r - 1);
	}
}

int isPalindrome(string s) {
	return recursion(s, 0, s.length() - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cnt = 0;

		string str;
		cin >> str;

		cout << isPalindrome(str) << " " << cnt << "\n";
	}
}  