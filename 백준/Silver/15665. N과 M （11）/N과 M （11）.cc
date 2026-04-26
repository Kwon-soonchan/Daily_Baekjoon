#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v;
vector<int> mask;
//vector<bool> visited;

void dfs(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << mask[i] << " ";
		}
		cout << "\n";
		return;
	}
	int last = -1;
	for (int i = 0; i < n; i++) {
		if (last == v[i]) {
			continue;
		}
		/*if(visited[i]) {
			continue;
		}*/

		//visited[i] = true;
		mask.push_back(v[i]);
		last = v[i];

		dfs(depth + 1);

		//visited[i] = false;
		mask.pop_back();
	}
}

int main() {
	cin >> n >> m;
	//visited.assign(n, false);

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	dfs(0);

	return 0;
}