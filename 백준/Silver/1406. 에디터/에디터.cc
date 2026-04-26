#include<iostream>
#include<string>
#include<list>
using namespace std;

int main() {
	string s;
	cin >> s;

	int n;
	cin >> n;

	list<char> lt;
	for (char c : s) {
		lt.push_back(c);
	}
	list<char>::iterator iter = lt.end();

	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;

		if (c == 'L') {
			if(iter != lt.begin()) {
				iter--;
			}
		}
		else if (c == 'D') {
			if(iter != lt.end()) {
				iter++;
			}
		}
		else if (c == 'B') {
			if(iter != lt.begin()) {
				iter--;
				iter = lt.erase(iter);
			}
		}
		else if (c == 'P') {
			char c2;
			cin >> c2;
			lt.insert(iter, c2);
		}
	}

	for(char c : lt) {
		cout << c;
	}
}