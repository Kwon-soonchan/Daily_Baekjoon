// 1260번 DFS와 BFS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[10001];
vector <int> graph[10001];
queue <int> q;

void dfs(int now) {
	visited[now] = true;

	cout << now << " ";

	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	visited[start] = true;
	q.push(start);
	
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		
		cout << now << " ";

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	int n, m, v, a, b;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i < n+1; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(v);
	cout << '\n';
	fill(visited, visited+sizeof(visited), 0);
	bfs(v);
}
