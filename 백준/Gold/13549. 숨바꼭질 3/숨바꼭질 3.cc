#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int> dist(100001, -1);

void bfs(int start) {
	deque<int> dq;
	dq.push_back(start);
	dist[start] = 0;

	while (!dq.empty()) {
		int cur = dq.front();
		dq.pop_front();

		// 0초이동
		if (cur * 2 <= 100000 && (dist[cur * 2] == -1 || dist[cur * 2] > dist[cur])) {
			dist[cur * 2] = dist[cur];
			dq.push_front(cur * 2);
		}

		// 1초이동
		if (cur + 1 <= 100000 && (dist[cur + 1] == -1 || dist[cur + 1] > dist[cur] + 1)) {
			dist[cur + 1] = dist[cur] + 1;
			dq.push_back(cur + 1);
		}
		if (cur - 1 >= 0 && (dist[cur - 1] == -1 || dist[cur - 1] > dist[cur] + 1)) {
			dist[cur - 1] = dist[cur] + 1;
			dq.push_back(cur - 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	bfs(n);

	cout << dist[k] << endl;
}