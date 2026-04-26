#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v;
vector<int> v2;

void dfs(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << v2[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		v2[depth] = v[i];
		dfs(depth + 1);
		v2.pop_back();
	}
}

int main() {
	cin >> n >> m;

	v.resize(n);
	v2.resize(m);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	dfs(0);
}