#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int answer;
int n, m, r;
int item[101];
int graph[101][101];
vector<pair<int, int>> edge[100];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				graph[i][j] = 0;
			}
			else {
				graph[i][j] = INF;
			}
		}
	}
    
	for (int i = 0; i < r; i++) {
		int from, to, dis;
		cin >> from >> to >> dis;
		edge[from].push_back({ to,dis });
		edge[to].push_back({ from,dis });
		graph[from][to] = dis;
		graph[to][from] = dis;
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] <= m) {
				cnt += item[j];
			}
		}
		answer = max(answer, cnt);
	}
	cout << answer;
	return 0;
}