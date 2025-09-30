#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> q;
	int front_idx = 0;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s == "push") {
			int x;
			cin >> x;

			q.push_back(x);
		}
		else if (s == "pop") {
			if (front_idx >= q.size()) {
				cout << -1 << "\n";
			}
			else {
				cout << q[front_idx] << "\n";
				front_idx++;
			}
		}
		else if (s == "size") {
			cout << q.size() - front_idx << "\n";
		}
		else if (s == "empty") {
			if (front_idx >= q.size()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (s == "front") {
			if (front_idx >= q.size()) {
				cout << -1 << "\n";
			}
			else {
				cout << q[front_idx] << "\n";
			}
		}
		else if (s == "back") {
			if (front_idx >= q.size()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.back() << "\n";
			}
		}
	}
}