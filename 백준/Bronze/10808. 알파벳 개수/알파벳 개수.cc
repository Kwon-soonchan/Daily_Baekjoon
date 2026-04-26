#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<int> v(26);

	for (char c : s) {
		v[c - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		cout << v[i] << " ";
	}
}