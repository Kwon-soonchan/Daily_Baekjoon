#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int s_x, s_y;
vector<vector<int>> board(1001);
vector<vector<int>> cnt(1001);
bool visited[1001][1001] = { 0, };
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;
	cnt[x][y] = 0;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny] || board[nx][ny] == 0) continue;
			visited[nx][ny] = true;
			cnt[nx][ny] = cnt[cx][cy] + 1;
			q.push({ nx, ny });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	board.assign(n, vector<int>(m, 0));
	cnt.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;

			board[i][j] = x;

			if (x == 2) {
				s_x = i;
				s_y = j;
			}
		}
	}

	bfs(s_x, s_y);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && visited[i][j] == 0) {
				cnt[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << cnt[i][j] << ' ';
		}
		cout << '\n';
	}
}