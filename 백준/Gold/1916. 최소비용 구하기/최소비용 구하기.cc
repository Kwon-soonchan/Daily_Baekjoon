// 1916번 최소비용 구하기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 2e9;
vector <pair<int, int>> graph[100001];
int distant[100001];

void dijkstra(int start) {
	fill(distant, distant + 100001, INF);
	priority_queue <pair<int, int>, vector <pair <int, int>>, greater<pair<int, int>>> pq;
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
	int n, m, start, end;
	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		graph[s].push_back({v, e});
	}

	cin >> start >> end;

	dijkstra(start);
	cout << distant[end];
}