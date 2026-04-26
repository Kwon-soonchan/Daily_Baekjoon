// 1275번 커피숍2
#include<iostream>
#include<vector>
#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;

int N, Q;
ll h = 1;
vector <ll> tree;

void update(int idx, ll value) {
	idx += h;
	tree[idx] = value;
	while (idx > 1) {
		idx /= 2;
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}
}

ll query(int L, int R, int node, int nodeL, int nodeR) {
	if (L <= nodeL && nodeR <= R) {
		return tree[node];
	}
	if (nodeR < L || R < nodeL) {
		return 0;
	}
	int mid = (nodeL + nodeR) / 2;
	return query(L, R, node * 2, nodeL, mid) + query(L, R, node * 2 + 1, mid + 1, nodeR);
}

int main() {
	fastio;
	cin >> N >> Q;
	while (N > h) {
		h <<= 1;
	}
	tree.resize(2 * h);

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		update(i, n);
	}

	for (int i = 0; i < Q; i++) {
		int x, y, a, b;
		ll result = 0;
		cin >> x >> y >> a >> b;
		if (x > y) {
			result = query(y, x, 1, 1, h);
		}
		else {
			result = query(x, y, 1, 1, h);
		}
		cout << result << '\n';
		update(a - 1, b);
	}
}