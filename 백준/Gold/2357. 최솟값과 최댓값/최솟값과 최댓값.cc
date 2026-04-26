// 2357번 최솟값과 최댓값
#include<iostream>
#include<vector>
#include<algorithm>
#define fastio  cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
int N, M;
ll h = 1;

vector <int> tree_min;
vector <int> tree_max;

void update_min(int idx, ll value) {
	idx += h;
	tree_min[idx] = value;
	while (idx > 1) {
		idx /= 2;
		tree_min[idx] = min(tree_min[idx * 2], tree_min[idx * 2 + 1]);
	}
}

void update_max(int idx, ll value) {
	idx += h;
	tree_max[idx] = value;
	while (idx > 1) {
		idx /= 2;
		tree_max[idx] = max(tree_max[idx * 2], tree_max[idx * 2 + 1]);
	}
}

ll query_min(int L, int R, int node, int nodeL, int nodeR) {
	if (L <= nodeL && nodeR <= R) {
		return tree_min[node];
	}
	if (nodeR < L || R < nodeL) {
		return 1e9;
	}
	int mid = (nodeL + nodeR) / 2;
	return min(query_min(L, R, node * 2, nodeL, mid), query_min(L, R, node * 2 + 1, mid + 1, nodeR));
}
ll query_max(int L, int R, int node, int nodeL, int nodeR) {
	if (L <= nodeL && nodeR <= R) {
		return tree_max[node];
	}
	if (nodeR < L || R < nodeL) {
		return 0;
	}
	int mid = (nodeL + nodeR) / 2;
	return max(query_max(L, R, node * 2, nodeL, mid), query_max(L, R, node * 2 + 1, mid + 1, nodeR));
}

int main() {
	fastio;
	cin >> N >> M;
	while (N > h) {
		h <<= 1;
	}
	tree_min.resize(2 * h);
	tree_max.resize(2 * h);

	for (int i = 0; i < N; i++) {
		ll n;
		cin >> n;
		update_min(i, n);
		update_max(i, n);
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << query_min(a, b, 1, 1, h) << ' ' << query_max(a, b, 1, 1, h) << '\n';

	}
}