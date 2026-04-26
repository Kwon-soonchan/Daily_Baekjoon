// 27498번 연애 혁명
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int N, M;
int sum = 0;
int cnt = 0;
vector<pii> graph[10001];

int prim() {
    priority_queue<pii> pq;
    vector<bool> visited(N + 1, false);
    visited[1] = true;
    for (pii edge : graph[1]) {
        pq.push(edge);
    }
    int cost = 0;
    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (!visited[node]) {
            visited[node] = true;
            cost += weight;

            for (pii next : graph[node]) {
                if (!visited[next.second]) {
                    pq.push(next);
                }
            }
        }
    }

    return cost - cnt * 10000;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    while (M--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        sum += c;

        if (d == 1) {
            c += 10000;
            cnt++;
        }
        graph[a].push_back({ c, b });
        graph[b].push_back({ c, a });
    }
    cout << sum - prim();
    return 0;
}