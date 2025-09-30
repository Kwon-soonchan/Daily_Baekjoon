#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int cnt = 1;
	stack<int> st;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x > cnt) {
			st.push(x);
		}
		else if (x == cnt) {
			v.push_back(x);
			cnt++;

			while (!st.empty() && st.top() == cnt) {
				v.push_back(st.top());
				st.pop();
				cnt++;
			}
		}
	}

	while (!st.empty()) {
		if (st.top() == cnt) {
			v.push_back(st.top());
			st.pop();
			cnt++;
		}
		else {
			break;
		}
	}

	if (st.empty()) {
		cout << "Nice" << "\n";
	}
	else {
		cout << "Sad" << "\n";
	}
}