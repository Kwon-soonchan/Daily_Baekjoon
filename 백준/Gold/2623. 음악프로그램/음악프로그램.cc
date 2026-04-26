// 2623번 음악프로그램
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int indegree[1'001];
vector <int> sum;
vector <int> graph[1'001];
queue <int> q;

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int count;
		int a, b;
		cin >> count;
		
		if (count == 0) continue;
		cin >> a;
		if (count == 1) continue;

		for (int j = 0; j < count-1; j++) {
			cin >> b;
			indegree[b]++;
			graph[a].push_back(b);
			a = b;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		sum.push_back(x);

		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			indegree[y]--;
			if (indegree[y] == 0) {
				q.push(y);
			}
		}
	}

	if (sum.size() != n) {
		cout << 0;
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << sum[i] << "\n";
		}
	}

	return 0;
}