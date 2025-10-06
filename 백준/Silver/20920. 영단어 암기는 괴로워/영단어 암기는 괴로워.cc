#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second != b.second) {
		return a.second > b.second;
	}

	if (a.first.length() != b.first.length()) {
		return a.first.length() > b.first.length();
	}

	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	map<string, int> words;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s.size() < m) {
			continue;
		}

		if (words.find(s) == words.end()) {
			words.insert({ s,1 });
		}
		else {
			words[s]++;
		}

	}
	vector<pair<string, int>> v(words.begin(), words.end());
	sort(v.begin(), v.end(), cmp);

	for (auto a : v) {
		cout << a.first << "\n";
	}
}