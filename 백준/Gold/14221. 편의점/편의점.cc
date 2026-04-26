// 14221번 편의점
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 5001;
const int INF = 2e9;

vector<pii> graph[MAX];
vector<int> house;
vector<int> conv;
int dist[MAX];

void dijkstra(int start) {
	priority_queue <pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) {
			continue;
		}

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nextCost = cost + graph[cur][i].second;

			if (nextCost < dist[next]) {
				dist[next] = nextCost;
				pq.push({ nextCost, next });
			}
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int j = 0; j < m; j++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	int p, q;
	cin >> p >> q;

	for (int i = 0; i < p; i++) {
		int a;
		cin >> a;
		house.push_back(a);
	}
	for (int i = 0; i < q; i++) {
		int a;
		cin >> a;
		conv.push_back(a);
	}

	int result = INF;
	int resultHouse = 0; 

	fill(dist, dist + MAX, INF);

	for (int i = 0; i < q; i++) {
		dijkstra(conv[i]);
	}

	for (int i = 0; i < p; i++) {
		if (dist[house[i]] < result) {
			result = dist[house[i]];
			resultHouse = house[i];
		}
		else if (dist[house[i]] == result && house[i] < resultHouse) {
			resultHouse = house[i];
		}
	}

	cout << resultHouse;

}