#include<iostream>
#include<string>
#include<set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;

	set<string> s;
	for (int i = 0; i < str.length(); i++) {
		for (int len = 1; i + len <= str.length(); len++) {
			s.insert(str.substr(i, len));
		}
	}

	int cnt = s.size();
	cout << cnt << "\n";
}