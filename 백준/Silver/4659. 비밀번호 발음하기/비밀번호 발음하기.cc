#include<iostream>
#include<string>
#include<vector>
using namespace std;

char jaum[21] = { 'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z' };
char moum[5] = { 'a','i','u','e','o' };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	while (true) {
		string s;
		cin >> s;
		bool check = false;
		
		if (s == "end") {
			break;
		}

		vector<bool> word(s.length());

		for (int i = 0; i < s.length(); i++) {
			for (char c : moum) {
				if (s[i] == c) {
					word[i] = 0;
					check = true;
				}
			}
			for (char c : jaum) {
				if (s[i] == c) {
					word[i] = 1;
				}
			}
		}

		bool isAcceptable = true;

		// 1. 모음 하나라도 없으면 바로 not acceptable
		if (!check) {
			cout << "<" << s << "> is not acceptable.\n";
			continue;
		}

		for (int i = 0; i < s.length(); i++) {
			if (i >= 1) {
				if (s[i] == s[i - 1]) {
					if (s[i] == 'e' || s[i] == 'o') {
						continue;
					}
					isAcceptable = false;
					break;
				}
			}
			if (i >= 2) {
				if (word[i] == 0 && word[i - 1] == 0 && word[i - 2] == 0) {
					isAcceptable = false;
					break;
				}
				else if (word[i] == 1 && word[i - 1] == 1 && word[i - 2] == 1) {
					isAcceptable = false;
					break;
				}
			}
		}
		if (isAcceptable) {
			cout << "<" << s << "> is acceptable.\n";
		} else {
			cout << "<" << s << "> is not acceptable.\n";
		}
	}
}