// 2638번 치즈
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> cheese;
vector<vector<bool>> visited;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs() {
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    visited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (valid(nx, ny) && !visited[nx][ny]) {
                if (cheese[nx][ny] == 0) {
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                }
                else {
                    cheese[nx][ny]++;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    cheese.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cheese[i][j];
        }
    }

    int time = 0;
    while (true) {
        visited.assign(n, vector<bool>(m, false));
        bfs();

        bool melted = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (cheese[i][j] > 2) {
                    cheese[i][j] = 0;
                    melted = true;
                }
                else if (cheese[i][j] != 0) {
                    cheese[i][j] = 1;
                }
            }
        }

        if (!melted) break;
        time++;
    }

    cout << time;
}