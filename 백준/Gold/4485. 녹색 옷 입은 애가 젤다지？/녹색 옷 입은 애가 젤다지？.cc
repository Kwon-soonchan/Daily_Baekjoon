// 4485번 녹색 옷 입은 애가 젤다지?
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, pair<int,int>> pipii;

const int MAX = 125;
const int INF = 2e9;

int dist[MAX][MAX];
int rupi[MAX][MAX];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void dijkstra(int startX, int startY, int N) {
    priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
    pq.push({ rupi[startX][startY], {startX, startY} });
    dist[startX][startY] = rupi[startX][startY];

    while (!pq.empty()) {
        int cost = pq.top().first;
        int curX = pq.top().second.first;
        int curY = pq.top().second.second;
        pq.pop();

        if (dist[curX][curY] < cost) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];

            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) {
                continue;
            }

            int nextCost = cost + rupi[nextX][nextY];

            if (nextCost < dist[nextX][nextY]) {
                dist[nextX][nextY] = nextCost;
                pq.push({ nextCost, {nextX,nextY} });
            }
        }
    }
}

int main() {
    int N;
    int cnt = 1;

    while (cin >> N) {
        if (N == 0) {
            break;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int k;
                cin >> k;
                rupi[i][j] = k;
                dist[i][j] = INF;
            }
        }

        dijkstra(0, 0, N);

        cout << "Problem " << cnt << ": " << dist[N - 1][N - 1] << '\n';
        cnt++;
    }
}