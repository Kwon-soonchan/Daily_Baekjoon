// 1922번 네트워크 연결
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int parrent[1'001];
vector<pair<int,int>> graph[100'001];
priority_queue <pair<int, pair<int, int>>> pq;

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
	int N, M;
	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++) {
		parrent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		pq.push({ -v, { s, e } });
	}

	cout << kruskal();

}