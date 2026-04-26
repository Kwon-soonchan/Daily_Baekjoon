#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> dist(100001, -1);

void bfs(int start) {
	queue<int> q;
	q.push(start);
	dist[start] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (dist[cur - 1] == -1) {
			dist[cur - 1] = dist[cur] + 1;
			q.push(cur - 1);
		}
		if (dist[cur + 1] == -1) {
			dist[cur + 1] = dist[cur] + 1;
			q.push(cur + 1);
		}
		if (cur * 2 <= 100000 && dist[cur * 2] == -1) {
			dist[cur * 2] = dist[cur] + 1;
			q.push(cur * 2);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	bfs(n);

	cout << dist[k] << endl;
}