#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	return a.length() < b.length();
}

int main() {
	int n;
	string s;
	cin >> n;
	vector <string> list;

	for (int i = 0; i < n; i++) {
		cin >> s;
		if (find(list.begin(), list.end(), s) == list.end()) {
			list.push_back(s);
		}
	}
	sort(list.begin(), list.end(), compare);
	for (string str : list) {
		cout << str << "\n";
	}
}