#include<iostream>
#include<queue>
#include<string>
using namespace std;

int arr[101][101];
int visited[101][101] = { 0, };
int dx[4] = { 0, 0, -1, 1 }; // 상, 하, 좌, 우
int dy[4] = { -1, 1, 0, 0 }; // 상, 하, 좌, 우

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == n - 1 && y == m - 1) {
            cout << visited[x][y] << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (arr[nx][ny] == 1 && visited[nx][ny] == 0) {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}