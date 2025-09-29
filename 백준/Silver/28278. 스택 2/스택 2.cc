#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> st;
	for (int i = 0; i < n; i++) {
		int order;
		cin >> order;

		if (order == 1) {
			int x;
			cin >> x;
			st.push_back(x);
		}
		else if (order == 2) {
			if (!st.empty()) {
				cout << st.back() << '\n';
				st.pop_back();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (order == 3) {
			cout << st.size() << '\n';
		}
		else if (order == 4) {
			if (!st.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << 1 << '\n';
			}
		}
		else if (order == 5) {
			if (!st.empty()) {
				cout << st.back() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
	}
}