#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int tree[100001];
vector<vector<int>> adj(100001);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	tree[1] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : adj[cur]) {
			if (tree[next] == 0) {
				tree[next] = cur;
				q.push(next);
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		cout << tree[i] << "\n";
	}
}