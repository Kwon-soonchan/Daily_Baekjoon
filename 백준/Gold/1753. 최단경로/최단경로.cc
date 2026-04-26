#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 2e9;
int distant[300001]; // 가중치
vector <pair<int, int>> graph[20001];

void dijkstra(int start) {
	fill(distant, distant+300001, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	distant[start] = 0;
	pq.push({ distant[start], start });

	while (!pq.empty()) {
		auto now = pq.top();
		pq.pop();

		if (distant[now.second] != now.first) {
			continue;
		}

		for (auto next : graph[now.second]) {
			if (distant[next.second] <= distant[now.second] + next.first) {
				continue;
			}
			distant[next.second] = distant[now.second] + next.first;
			pq.push({ distant[next.second], next.second });
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int V, E, K;
	cin >> V >> E; // 정점, 간선
	cin >> K; // 시작 정점

	for (int i = 0; i < E; i++) {
		int u, v, w; // vertex, edge, weight
		cin >> u >> v >> w;
		graph[u].push_back({ w,v });
	}
	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (distant[i] == 2e9) {
			cout << "INF" << '\n';
		}
		else {
			cout << distant[i] << '\n';
		}
	}
}