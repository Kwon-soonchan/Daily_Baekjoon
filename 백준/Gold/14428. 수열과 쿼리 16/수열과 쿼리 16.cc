// 14428번 수열과 쿼리 16
#include<iostream>
#include<vector>
#include<algorithm>
#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int N, M;
ll h = 1;
vector <pll> tree;

void update(int idx, ll value) {
	idx += h;
	tree[idx] = { value, idx - h + 1 };
	while (idx > 1) {
		idx /= 2;
		if (tree[idx * 2].first <= tree[idx * 2 + 1].first) {
			tree[idx] = tree[idx * 2];
		}
		else {
			tree[idx] = tree[idx * 2 + 1];
		}
	}
}

pll query(int L, int R, int node, int nodeL, int nodeR) {
	if (L <= nodeL && nodeR <= R) {
		return tree[node];
	}
	if (nodeR < L || R < nodeL) {
		return {2e9, -1};
	}
	int mid = (nodeL + nodeR) / 2;
	pll left = query(L, R, node * 2, nodeL, mid);
	pll right = query(L, R, node * 2 + 1, mid + 1, nodeR);
	return left.first <= right.first ? left : right;
}

int main() {
	fastio;
	cin >> N;
	while (N > h) {
		h <<= 1;
	}
	tree.resize(2 * h, {1e9, -1});

	for (int i = 0; i < N; i++) {
		ll n;
		cin >> n;
		update(i, n);
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(b - 1, c);
		}
		else if (a == 2) {
			pll result = query(b, c, 1, 1, h);
			cout << result.second << '\n';
		}
	}
}