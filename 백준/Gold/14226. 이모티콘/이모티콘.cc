#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<vector<int>> dist(1001, vector<int>(1001,-1));

void bfs(int start) {
	queue<pair<int,int>> q;
	q.push({ start, 0 });
	dist[start][0] = 0;

	while (!q.empty()) {
		int cur = q.front().first;
		int clip = q.front().second;
		q.pop();

		if (dist[cur][cur] == -1) {
			dist[cur][cur] = dist[cur][clip] + 1;
			q.push({ cur,cur });
		}
		if (cur + clip <= 1000 && dist[cur + clip][clip] == -1) {
			dist[cur + clip][clip] = dist[cur][clip] + 1;
			q.push({ cur + clip , clip });
		}
		if (cur - 1 >= 0 && dist[cur - 1][clip] == -1) {
			dist[cur - 1][clip] = dist[cur][clip] + 1;
			q.push({ cur - 1,clip });
		}
	}
}

int main() {
	int s;
	cin >> s;

	bfs(1);

	int min_s = 2e9;
	for (int i = 0; i <= 1000; i++) {
		if (dist[s][i] != -1) {
			min_s = min(dist[s][i], min_s);
		}
	}
	cout << min_s << endl;
}