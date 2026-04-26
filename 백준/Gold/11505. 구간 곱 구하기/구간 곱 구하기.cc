// 11505번 구간 곱 구하기
#include<iostream>
#include<vector>
#define fastio  cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;

int N, M, K;
ll h = 1;
vector <ll> tree;

void update(int idx, ll value) {
	idx += h;
	tree[idx] = value;
	while (idx > 1) {
		idx /= 2;
		tree[idx] = (tree[idx * 2] * tree[idx * 2 + 1]) % 1'000'000'007;
	}
}

ll query(int L, int R, int node, int nodeL, int nodeR) {
	if (L <= nodeL && nodeR <= R) {
		return tree[node];
	}
	if (nodeR < L || R < nodeL) {
		return 1;
	}
	int mid = (nodeL + nodeR) / 2;
	return (query(L, R, node * 2, nodeL, mid) * query(L, R, node * 2 + 1, mid + 1, nodeR)) % 1'000'000'007;
}

int main() {
	fastio;
	cin >> N >> M >> K;
	while (N > h) {
		h <<= 1;
	}
	tree.resize(2 * h);

	for (int i = 0; i < N; i++) {
		ll n;
		cin >> n;
		update(i, n);
	}

	for (int i = 0; i < M + K; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(b-1, c);
		}
		else if (a == 2) {
			ll result = query(b, c, 1, 1, h);
			cout << result << '\n';
		}
	}
}