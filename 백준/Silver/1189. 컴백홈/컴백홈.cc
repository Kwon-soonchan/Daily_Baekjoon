// 1189번 컴백홈
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int R, C, K;
int result = 0;
char map[5][5];
bool visited[5][5];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void dfs(int x, int y, int cnt) {
	if (x == 0 && y == C-1) {
		if (cnt == K) {
			result++;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
			if (!visited[nx][ny] && map[nx][ny] != 'T') {
				visited[nx][ny] = true;
				dfs(nx, ny, cnt + 1);
				visited[nx][ny] = false;
			}
		}
	}
}

int main() {

	cin >> R >> C >> K;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	visited[R-1][0] = true;
	dfs(R-1, 0, 1);

	cout << result << '\n';
}