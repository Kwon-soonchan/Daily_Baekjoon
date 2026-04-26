#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 2e9;
int tc, n, m, w;
int distant[501];
bool flag;
vector <pair<int, int>> graph[501];

void bellman_Ford() {
fill(distant, distant+n+1, INF);
distant[1] = 0;
flag = false;

for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= n; j++) {
		for (int k = 0; k < graph[j].size(); k++) {
			int next = graph[j][k].first;
			int ncost = graph[j][k].second;

			if (distant[next] > distant[j] + ncost) {
				distant[next] = distant[j] + ncost;
				if (i == n) {
					flag = true;
				}
			}
		}
	}
}
if (flag) {
	cout << "YES" << '\n';
}
else {
	cout << "NO" << '\n';
}
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
cin >> tc;

for (int i = 0; i < tc; i++) {
	cin >> n >> m >> w;
	
	for (int j = 0; j < m; j++) {
		int s, e, t;
		cin >> s >> e >> t;
		graph[s].push_back({ e,t });
		graph[e].push_back({ s,t });
	}
	for (int j = 0; j < w; j++) {
		int s, e, t;
		cin >> s >> e >> t;
		graph[s].push_back({ e, -t });
	}
	bellman_Ford();

	for (int j = 1; j <= n; j++) {
		graph[j].clear();
	}
}
}