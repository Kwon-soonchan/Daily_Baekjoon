#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	vector<int> v2;
	map<int, int> m;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v2.push_back(v[i]);

	}

	sort(v2.begin(), v2.end());
	v2.erase(unique(v2.begin(), v2.end()), v2.end());

	for (int i = 0; i < v2.size(); i++) {
		m[v2[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		cout << m[v[i]] << ' ';
	}
}