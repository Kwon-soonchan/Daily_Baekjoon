// 14466번 소가 길을 건너간 이유6
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, k, R;
bool visited[101][101];
int arr[101][101][4] = { 0, };
int x_ar[4] = { 0,1,0,-1 };
int y_ar[4] = { -1,0,1,0 };
int result = 0;
vector <pair<int, int>> cow;

void bfs(int sy, int sx) {
	queue <pair<int, int >> q;
	q.push(make_pair(sy, sx));
	visited[sy][sx] = 1;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			if (arr[cy][cx][i] == 1) continue;
			int ny = cy + y_ar[i];
			int nx = cx + x_ar[i];

			if (ny <1 || ny > n || nx < 1 || nx > n || visited[ny][nx] == 1)
				continue;
			q.push(make_pair(ny, nx));
			visited[ny][nx] = 1;
		}



	}


}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k >> R;

	int r, c, rr, cc;
	for (int i = 0; i < R; i++) {
		cin >> r >> c >> rr >> cc;
		for (int j = 0; j < 4; j++) {
			int nr = r + y_ar[j];
			int nc = c + x_ar[j];
			if (nr == rr && nc == cc) {
				arr[r][c][j] = 1;
				arr[rr][cc][(j + 2) % 4] = 1;
			}
		}
	}

	for (int i = 0; i < k; i++) {
		cin >> r >> c;
		cow.push_back(make_pair(r, c));
	}

	for (int i = 0; i < k; i++) {
		memset(visited, 0, sizeof(visited));
		bfs(cow[i].first, cow[i].second);

		for (int j = i + 1; j < k; j++) {
			if (visited[cow[j].first][cow[j].second] == 0)
				result++;
		}
	}


	cout << result;
}