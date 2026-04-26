#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool flag = false;
vector<int> v;
vector<vector<int>> v2;
stack<int> s;

void solve() {
	int idx = 0;
	for (int i = 1; i <= v.size(); i++) {
		s.push(i);
		v2.push_back({ i,1 });
		while (!s.empty() && s.top() == v[idx]) {
			s.pop();
			v2.push_back({ v[idx],0 });
			idx++;
		}
		if (s.empty() && idx == v.size()) {
			break;
		}
		if (!s.empty() && s.top() > v[idx]) {
			cout << "NO" << endl;
			flag = true;
			return;
		}
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	solve();

	if (flag) {
		return 0;
	}

	for (auto& i : v2) {
		if (i[1] == 1) {
			cout << "+" << '\n';
		}
		else {
			cout << "-" << '\n';
		}
	}
}