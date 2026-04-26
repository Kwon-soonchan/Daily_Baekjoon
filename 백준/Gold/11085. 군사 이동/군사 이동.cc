// 11085번 군사 이동
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> parent(1000);
vector<pair<int, pair<int, int>>> edges;

int find(int n) {
	if (parent[n] == n) {
		return n;
	}
	return parent[n] = find(parent[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		parent[a] = b;
	}
}

int main() {
	int p, w, c, v;
	cin >> p >> w;
	cin >> c >> v;

	for (int i = 0; i < p; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < w; i++) {
		int ws, we, ww;
		cin >> ws >> we >> ww;

		edges.push_back({ -ww, {ws,we} });
	}

	sort(edges.begin(), edges.end());

	int Min = 2e9;

	for (auto edge : edges) {
		int ww = -edge.first;
		int ws = edge.second.first;
		int we = edge.second.second;

		if (find(ws) != find(we)) {
			merge(ws, we);
			Min = min(Min, ww);

			if (find(c) == find(v)) {
				break;
			}
		}
	}

	cout << Min;
}