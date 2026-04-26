#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v;
vector<int> num;
vector<bool> visited;

void dfs(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < num.size(); i++) {
		if (visited[i]) {
			continue;
		}
		visited[i] = true;
		v.push_back(num[i]);
		dfs(depth + 1);
		v.pop_back();
		visited[i] = false;
	}
}

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		num.push_back(x);
	}
	sort(num.begin(), num.end());
	visited.resize(n, false);

	dfs(0);

	return 0;
}