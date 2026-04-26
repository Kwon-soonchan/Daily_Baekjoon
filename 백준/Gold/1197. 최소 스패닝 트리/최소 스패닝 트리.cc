// 1197번 최소 스패닝 트리
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int parrent[10'001];
vector<pair<int,int>> graph[100'001];
priority_queue <pair<int, pair<int, int>>> pq;

int V, E;

int find(int a) {
	if (parrent[a] == a) {
		return a;
	}
	else {
		return parrent[a] = find(parrent[a]);
	}
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);

	if (parrent[a] != parrent[b]) {
		parrent[b] = a;
	}
}

int kruskal() {
	int result = 0;

	while (!pq.empty()) {
		int u = find(pq.top().second.first);
		int v = find(pq.top().second.second);
		int cost = -pq.top().first;

		pq.pop();

		if (u == v) continue;
		else {
			Union(u, v);
			result += cost;
		}
	}

	return result;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	cin >> V >> E;

	for (int i = 0; i < V; i++) {
		parrent[i] = i;
	}

	for (int i = 0; i < E; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		pq.push({ -v, { s, e } });
	}

	cout << kruskal();

}