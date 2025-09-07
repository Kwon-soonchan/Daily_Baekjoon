#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0, };
int safeZone = 0;
vector<vector<int>> board;
vector<pair<int,int>> virus;
vector<pair<int, int>> zeros;

void bfs() {
	queue<pair<int,int>> q;
	vector<vector<int>> temp_board = board;
	
	for (int i = 0; i < virus.size(); i++) {
		q.push(virus[i]);
	}

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];

			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
				if (temp_board[next_x][next_y] == 0) {
					temp_board[next_x][next_y] = 2;
					q.push({ next_x,next_y });
				}
			}
		}
	}

	int cur_safeZone = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp_board[i][j] == 0) {
				cur_safeZone++;
			}
		}
	}
	safeZone = max(safeZone, cur_safeZone);
}

void wallMaker(int cnt, int start) {
	if (cnt == 3) {
		bfs();
		return;
	}

	for (int i = start; i < zeros.size(); i++) {
		int x = zeros[i].first;
		int y = zeros[i].second;

		board[x][y] = 1;
		wallMaker(cnt + 1, i + 1);
		board[x][y] = 0;
	}
}

int main() {
	cin >> n >> m;

	board.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];

			if (board[i][j] == 2) {
				virus.push_back({ i,j });
			}
			else if (board[i][j] == 0) {
				zeros.push_back({ i,j });
			}
		}
	}

	wallMaker(0, 0);

	cout << safeZone << endl;
}