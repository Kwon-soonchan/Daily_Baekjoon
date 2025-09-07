#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
vector<vector<int>> board;

void bfs() {
	queue<pair<int,int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 0) {
				board[nx][ny] = board[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	cin >> m >> n;
	board.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			board[i][j] = x;
		}
	}
	
	bfs();

	int result = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				cout << -1 << endl;
				return 0;
			}
			result = max(result, board[i][j]);
		}
	}
	cout << result - 1 << endl;
}