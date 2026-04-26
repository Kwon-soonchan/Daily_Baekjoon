#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> board;
bool visited[51][51] = { 0, };
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int m, n, k;
		cin >> m >> n >> k;

		board.resize(n, vector<int>(m, 0));

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}

		int count = 0;

		queue<pair<int, int>> q;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1 && !visited[i][j]) {
					q.push({ j, i });
					visited[i][j] = true;
					count++;

					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();

						for (int i = 0; i < 4; i++) {
							int nx = x + dx[i];
							int ny = y + dy[i];
							if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

							if (visited[ny][nx]) continue;
							if (board[ny][nx] == 0) continue;

							if (board[ny][nx] == 1 && visited[ny][nx] == 0) {
								q.push({ nx, ny });
								visited[ny][nx] = true;
							}
						}
					}
				}
			}
		}
		cout << count << '\n';
		board.clear();
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				visited[i][j] = false;
			}
		}
	}
}