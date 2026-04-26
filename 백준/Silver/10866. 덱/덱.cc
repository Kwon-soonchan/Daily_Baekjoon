// 10866번 덱
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s == "push_back") {
			int a;
			cin >> a;
			v.push_back(a);
		}
		else if (s == "push_front") {
			int a;
			cin >> a;
			v.insert(v.begin(), a);
		}
		else if (s == "pop_back") {
			if (v.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << v.back() << "\n";
				v.pop_back();
			}
		}
		else if (s == "pop_front") {
			if (v.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << v.front() << "\n";
				v.erase(v.begin());
			}
		}
		else if (s == "size") {
			cout << v.size() << "\n";
		}
		else if (s == "empty") {
			if (v.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (s == "front") {
			if (v.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << v.front() << "\n";
			}
		}
		else if (s == "back") {
			if (v.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << v.back() << "\n";
			}
		}
	}
}