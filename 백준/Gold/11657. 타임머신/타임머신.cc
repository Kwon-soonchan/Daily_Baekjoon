#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 2e9;
long long distant[501];
bool flag=false;
vector <pair<int, int>> graph[501];
int n, m;

void bellman_Ford(int start) {
	fill(distant, distant+n+1, INF);
	distant[start] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < graph[j].size(); k++) {
				int next = graph[j][k].first;
				int ncost = graph[j][k].second;

				if ((distant[j] != INF) && (distant[next] > distant[j] + ncost)) {
					distant[next] = distant[j] + ncost;
					if (i == n) {
						flag = true;
					}
				}
			}
		}
	}
	if (flag) {
		cout << -1 << '\n';
	}
	else {
		for (int i = 2; i <= n; i++) {
			cout << (distant[i] != INF ? distant[i] : -1) << '\n';
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}

	bellman_Ford(1);
}