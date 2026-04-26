#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<char> v;

int main() {
	string s;
	cin >> s;

	for (char c : s) {
		v.push_back(c);
	}

	sort(v.begin(), v.end(), greater<char>());

	for (char c : v) {
		cout << c;
	}
}