#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	getline(cin, s);

	for (char c : s) {
		if(c >= 'A' && c <= 'Z') {
			c = (c - 'A' + 13) % 26 + 'A';
		} else if(c >= 'a' && c <= 'z') {
			c = (c - 'a' + 13) % 26 + 'a';
		}
		cout << c;
	}
}