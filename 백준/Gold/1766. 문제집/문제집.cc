// 1766번 문제집
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int indegree[32'001];
vector <int> graph[32'001];
priority_queue <int, vector<int>, greater<int>> pq;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		indegree[b]++; // 진입차수
		graph[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int x = pq.top();
		pq.pop();

		cout << x << ' ';

		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			indegree[y]--;
			if (indegree[y] == 0) {
				pq.push(y);
			}
		}
	}
	return 0;
}
