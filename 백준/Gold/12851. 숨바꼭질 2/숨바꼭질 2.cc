#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> dist(100001, -1);
vector<int> cnt(100001, 0);

void bfs(int start) {
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	cnt[start] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : {cur - 1, cur + 1, cur * 2}) {
			if (next < 0 || next>100000) {
				continue;
			}
			if (dist[next] == -1) {
				dist[next] = dist[cur] + 1;
				cnt[next] = cnt[cur];
				q.push(next);
			}
			else if (dist[next] == dist[cur] + 1) {
				cnt[next] += cnt[cur];
			}
		}
		if (dist[cur + 1] == -1) {
			dist[cur + 1] = dist[cur] + 1;
			q.push(cur + 1);
		}
		if (dist[cur - 1] == -1) {
			dist[cur - 1] = dist[cur] + 1;
			q.push(cur - 1);
		}
		if (cur * 2 <= 100000 && dist[cur * 2] == -1) {
			dist[cur * 2] = dist[cur] + 1;
			q.push(cur * 2);
		}

	}

}

int main() {
	int n, k;
	cin >> n >> k;

	bfs(n);

	cout << dist[k] << endl << cnt[k] << endl;
}