// 1238번 파티
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 2e9;
int distant_back[1'001];
vector <int> distant[2];
vector <pair<int,int>> graph[2][1'001];
int n, m, x;

void dijkstra(int start) {
	distant[start][x] = 0;
	priority_queue <pair<int, int>, vector <pair<int, int>>, greater <pair<int, int>>> pq;
	pq.push({ 0, x });

	while (!pq.empty()) {
		auto back = pq.top().first;
		auto now = pq.top().second;
		pq.pop();

		if (back > distant[start][now]) {
			continue;
		}

		for (int i = 0; i < graph[start][now].size(); i++) {
			int next = graph[start][now][i].second;
			int next_back = back + graph[start][now][i].first;

			if (next_back < distant[start][next]) {
				distant[start][next] = next_back;
				pq.push({ next_back, next });
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	fill(distant_back, distant_back + 1001, INF);

	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		graph[0][s].push_back({ t, e }); // x번 마을에서 돌아갈때
		graph[1][e].push_back({ t, s }); // x번 마을로 모일때
	}
	distant[0].resize(n + 1, INF);
	distant[1].resize(n + 1, INF);
	
	dijkstra(0);
	dijkstra(1);

	int result = 0;

	for (int i = 1; i <= n; i++) {
		result = max(result, distant[0][i] + distant[1][i]);
	}
	cout << result << '\n';
}