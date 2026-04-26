#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int m, n, h;
int dx[6] = { 0,0,-1,1,0,0, };
int dy[6] = { -1,1,0,0,0,0, };
int dz[6] = { 0,0,0,0,-1,1 };
vector<vector<vector<int>>> status_tomato;
vector<vector<vector<int>>> day;
vector<pair<int, pair<int,int>>> rotten_tomato;

void bfs(const vector<pair<int,pair<int,int>>>& rotten_tomatos) {
	queue<pair<int, pair<int, int>>> q;
	// 익은 토마토를 queue에 추가
	for (const auto& tomato : rotten_tomatos) {
		q.push(tomato);
		day[tomato.first][tomato.second.first][tomato.second.second] = 0;
	}

	while (!q.empty()) {
		int cur_z = q.front().first;
		int cur_y = q.front().second.first;
		int cur_x = q.front().second.second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = cur_z + dz[i];
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];

			if (nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m) {
				continue;
			}

			if (status_tomato[nz][ny][nx] == 0) {
				status_tomato[nz][ny][nx] = 1;
				day[nz][ny][nx] = day[cur_z][cur_y][cur_x] + 1;
				q.push({ nz, {ny,nx} });
			}
		}
	}
}

int main() {
	cin >> m >> n >> h;
	status_tomato.resize(h, vector<vector<int>>(n, vector<int>(m)));
	day.resize(h, vector<vector<int>>(n, vector<int>(m)));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int tomato;
				cin >> tomato;
				status_tomato[i][j][k] = tomato;

				if (tomato == 1) {
					rotten_tomato.push_back({ i, {j,k} });
				}
			}
		}
	}

	bfs(rotten_tomato);

	int max_day = 0;
	bool not_all = false;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				max_day = max(max_day, day[i][j][k]);
				if (status_tomato[i][j][k] == 0) {
					not_all = true;
				}
			}
		}
	}

	if (not_all) {
		cout << -1 << endl;
	}
	else {
		cout << max_day << endl;
	}
}