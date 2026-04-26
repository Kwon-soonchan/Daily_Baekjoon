#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;

bool isPal(const string& str) {
	if (str.empty()) {
		return false;
	}

	int l = 0;
	int r = str.length() - 1;

	while (l < r) {
		if (str[l] != str[r]) {
			return false;
		}
		l++;
		r--;
	}
	return true;
}

bool compare(const string& a, const string& b) {
	if (a.length() == b.length()) {
		return false;
	}
	return a.length() < b.length();
}

int main() {
	string s;

	while (cin >> s) {
		vector<string> v;
		unordered_set<string> us;

		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < s.length(); j++) {
				string sub = s.substr(i, j - i + 1);

				if (isPal(sub) && us.find(sub) == us.end()) {
					v.push_back(sub);
					us.insert(sub);
				}
			}
		}

		sort(v.begin(), v.end(), compare);

		cout << v.size() << " - ";
		
		for (const auto& p : v) {
			cout << "\"" << p << "\" ";
		}
		cout << '\n';
	}
}