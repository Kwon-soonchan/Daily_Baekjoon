// 1764번 듣보잡
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> v;
	unordered_set<string> us;

	string s;

	for(int i = 0; i < n; i++) {
		cin >> s;
		us.insert(s);
	}

	for (int i = 0; i < m; i++) {
		cin >> s;
		if (us.find(s) != us.end()) {
			v.push_back(s);
		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}