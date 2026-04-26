// 10828번 스택
#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> v;

int stack_jjap(string s, int n) {
	if (s == "push") {
		v.push_back(n);
	}
	else if (s == "pop") {
		if (v.empty()) {
			cout << -1 << '\n';
		}
		else {
			cout << v.back() << '\n';
			v.pop_back();
		}
	}
	else if (s == "size") {
		cout << v.size() << '\n';
	}
	else if (s == "empty") {
		if (v.empty()) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
	else if (s == "top") {
		if(v.empty()) {
			cout << -1 << '\n';
		}
		else {
			cout << v.back() << '\n';
		}
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s == "push") {
			int m;
			cin >> m;

			stack_jjap(s, m);
		}
		else {
			stack_jjap(s, 0);
		}
	}
}