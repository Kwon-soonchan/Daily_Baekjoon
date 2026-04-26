// 1584번 게임
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> pipii;

const int MAX = 501;
const int INF = 2e9;

int board[MAX][MAX];
int dist[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dijkstra() {
    priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
    pq.push({ 0, {0, 0} });
    dist[0][0] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (dist[x][y] < cost) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) {
                continue;
            }
            if (board[nx][ny] == 2 ) {
                continue;
            }

            int nextCost = cost + (board[nx][ny] == 1 ? 1 : 0);
            if (nextCost < dist[nx][ny]) {
                dist[nx][ny] = nextCost;
                pq.push({ nextCost, {nx, ny} });
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = min(x1, x2); x <= max(x1, x2); x++) {
            for (int y = min(y1, y2); y <= max(y1, y2); y++) {
                board[x][y] = 1;
            }
        }
    }

    cin >> M;

    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = min(x1, x2); x <= max(x1, x2); x++) {
            for (int y = min(y1, y2); y <= max(y1, y2); y++) {
                board[x][y] = 2;
            }
        }
    }

    fill(&dist[0][0], &dist[MAX - 1][MAX], INF);
    dijkstra();

    if (dist[500][500] != INF) {
        cout << dist[500][500];
    }
    else {
        cout << -1;
    }
}