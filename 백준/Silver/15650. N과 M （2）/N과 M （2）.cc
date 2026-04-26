#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v;

void dfs(int st, int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = st; i <= n; i++) {
		v.push_back(i);
		dfs(i + 1, depth + 1);
		v.pop_back();
	}
}

int main() {
	cin >> n >> m;

	dfs(1, 0);

	return 0;
}