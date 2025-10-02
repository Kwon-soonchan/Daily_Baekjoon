#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	deque<int> dq;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (v[i] == 0) {
			dq.push_front(x);
		}
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;

		dq.push_back(x);
		cout << dq.front() << " ";
		dq.pop_front();
	}
}