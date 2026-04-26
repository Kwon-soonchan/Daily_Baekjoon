#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> dist(100001, -1);
vector<int> load(100001, -1);

void bfs(int start) {
	queue<int> q;
	dist[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : {cur + 1, cur - 1, cur * 2}) {
			if ((next >= 0 && next <= 100000) && dist[next] == -1) {
				dist[next] = dist[cur] + 1;
				load[next] = cur;
				q.push(next);
			}
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	bfs(n);

	cout << dist[k] << endl;

	vector<int> path;
	for (int cur = k; cur != -1; cur = load[cur]) {
		path.push_back(cur);
	}
	reverse(path.begin(), path.end());

	for (int i : path) {
		cout << i << " ";
	}
}