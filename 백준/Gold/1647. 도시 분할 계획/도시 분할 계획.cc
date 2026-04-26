// 1674번 도시 분할 계획
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int parrent[100'001];
vector <pair<int, int>> graph[1'000'001];
priority_queue <pair<int, pair<int, int>>> pq;

int Find(int a) {
	if (parrent[a] == a) {
		return a;
	}
	else {
		return parrent[a] = Find(parrent[a]);
	}
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (parrent[a] != parrent[b]) {
		parrent[b] = a;
	}
}

int kruskal() {
	int result = 0;
	int last = 0;

	while (!pq.empty()) {
		int u = Find(pq.top().second.first);
		int v = Find(pq.top().second.second);
		int cost = -pq.top().first;

		pq.pop();

		if (u == v) {
			continue;
		}
		else {
			Union(u, v);
			result += cost;
			last = cost;
		}
	}

	return result - last;

}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int m, n;
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		parrent[i] = i;
	}

	for (int i = 0; i < n; i++) {
		graph[i].clear();
	}

	for (int i = 0; i < n; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		pq.push({ -v, {s,e} });
	}

	cout << kruskal() << "\n";
		
}
