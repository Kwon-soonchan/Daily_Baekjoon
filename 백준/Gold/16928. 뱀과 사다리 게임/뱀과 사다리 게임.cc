#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
int dist[101];
int board[101];

void bfs(int start) {
	queue<int>q;
	q.push(start);
	for (int i = 0; i <= 100; i++) {
		dist[i] = -1;
	}
	dist[start] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int next = cur + i;
			if (next > 100) {
				continue;
			}

			int final_dest = board[next];

			if (dist[final_dest] == -1) {
				dist[final_dest] = dist[cur] + 1;
				q.push(final_dest);
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= 100; i++) {
		board[i] = i;
	}
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		board[x] = y;
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		board[u] = v;
	}

	bfs(1);

	cout << dist[100] << endl;
}