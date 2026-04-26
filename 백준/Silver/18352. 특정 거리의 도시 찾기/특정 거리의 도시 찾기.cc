// 18352번 특정 거리의 도시 찾기
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
const int INF = 2e9;

int n, m, k, x;

vector<int> dist;

void dijkstra(int start, vector<vector<int>> graph, int n) {
	// 시작점으로부터 거리 정보를 저장할 배열, 최댓값으로 초기화 필수!
	dist.assign(n + 1, INF);
	// 시작점을 1이라고 가정
	dist[start] = 0;

	priority_queue <pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) {
			continue;
		}
		for (int next : graph[here]) {
			int nextcost = cost + 1;;

			if (dist[next] > nextcost) {
				dist[next] = nextcost;
				pq.push({ nextcost,next });
			}
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k >> x;

	vector<vector<int>> g(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
	}

	dijkstra(x, g, n);

	vector<int> result;

	for (int i = 1; i <= n; i++) {
		if (dist[i] == k) {
			result.push_back(i);
		}
	}

	if (result.empty()) {
		cout << -1;
	}
	else {
		for (int city : result) {
			cout << city << '\n';
		}
	}
}