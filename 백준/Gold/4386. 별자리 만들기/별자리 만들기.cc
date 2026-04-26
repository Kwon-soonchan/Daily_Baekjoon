// 4386번 별자리 만들기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int parent[101];
vector<pair<double, double>> stars;
priority_queue<pair<double, pair<double, double>>> pq;

int find(int a) {
    if (parent[a] == a) {
        return a;
    }
    else {
        return parent[a] = find(parent[a]);
    }
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);

    if (parent[a] != parent[b]) {
        parent[b] = a;
    }
}

double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double kruskal() {
    double result = 0.0;

    while (!pq.empty()) {
        int u = find(pq.top().second.first);
        int v = find(pq.top().second.second);
        double cost = -pq.top().first;

        pq.pop();

        if (u == v) continue;
        else {
            Union(u, v);
            result += cost;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        stars.push_back(make_pair(x, y));
    }

    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double distance = calculateDistance(stars[i].first, stars[i].second, stars[j].first, stars[j].second);
            pq.push({ -distance, {i, j} });
        }
    }

    cout.precision(3);
    cout << fixed << kruskal() << "\n";

    return 0;
}
