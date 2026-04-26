#include<iostream>
#include<string>
#include<vector>
using namespace std;

string ab[2] = { "AAAA", "BB" };
vector<vector<string>> v;
vector<string> result;

int main() {
	string s;
	cin >> s;

	int section = 1;
	for (char c : s) {
		if (c == '.') section++;
	}

	v.resize(section);

	int idx = 0;
	
	for (char c : s) {
		if (c == '.') {
			idx++;
		}
		else if (c == 'X') {
			v[idx].push_back("X");
		}
	}

	for (int i = 0; i < v.size(); i++) {
		int len = v[i].size();

		if (v[i].size() % 2 == 1) {
			cout << -1;
			return 0;
		}
		else {
			string temp;
			while (len >= 4) {
				temp += ab[0];
				len -= 4;
			}
			while (len >= 2) {
				temp += ab[1];
				len -= 2;
			}
			result.push_back(temp);
		}
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
		if (i != result.size() - 1) cout << '.';
	}
}