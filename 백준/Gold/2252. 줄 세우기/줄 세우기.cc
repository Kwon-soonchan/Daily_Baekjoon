// 2252번 줄 세우기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int index[32'001];
vector <int> graph[32'001];
queue <int> q;

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		index[b]++; // 진입차수
		graph[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		if (index[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " ";
		
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			index[y]--;
			if (index[y] == 0) {
				q.push(y);
			}
		}
	}
	return 0;
}
