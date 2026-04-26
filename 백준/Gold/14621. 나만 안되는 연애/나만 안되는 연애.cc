// 14621번 나만 안되는 연애
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1000;

int N, M;
char gender[MAX_N + 1];
vector<pair<int, pair<int, int>>> edges;
int parent[MAX_N + 1];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unionSet(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);
    if (parentA != parentB) {
        parent[parentB] = parentA;
    }
}

int kruskal() {
    int totalDist = 0;
    int count = 0;
    for (auto edge : edges) {
        int dist = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (find(u) != find(v)) {
            unionSet(u, v);
            totalDist += dist;
            count++;
        }

        if (count == N - 1) break;
    }

    if (count != N - 1) return -1;

    return totalDist;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> gender[i];
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        if (gender[u] != gender[v]) {
            edges.push_back({ d, {u, v} });
        }
    }

    sort(edges.begin(), edges.end());

    int result = kruskal();
    cout << result << '\n';

    return 0;
}