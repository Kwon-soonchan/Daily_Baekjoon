// 5676번 음주 코딩
#include<iostream>
#include<vector>
#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;

int N, K;
ll h = 1;
vector <ll> tree;
vector <ll> arr;

void update(int idx, ll value) {
	idx += h;
	tree[idx] = value;
	while (idx > 1) {
		idx /= 2;
		tree[idx] = tree[idx * 2] * tree[idx * 2 + 1];
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
	return query(L, R, node * 2, nodeL, mid) * query(L, R, node * 2 + 1, mid + 1, nodeR);
}

int main() {
	fastio;
	while (cin >> N >> K) {
		h = 1;
		tree.clear();

		while (N > h) {
			h <<= 1;
		}
		tree.resize(2 * h);

		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			if (n > 0) {
				update(i, 1);
			}
			else if (n < 0) {
				update(i, -1);
			}
		}

		for (int i = 0; i < K; i++) {
			int a, b;
			char c;
			cin >> c >> a >> b;
			if (c == 'C') {
				if (b > 0) {
					update(a - 1, 1);
				}
				else if (b < 0) {
					update(a - 1, -1);
				}
				else {
					update(a - 1, 0);
				}
			}
			else if (c == 'P') {
				ll result = query(a, b, 1, 1, h);

				if (result > 0) {
					cout << '+';
				}
				else if (result == 0) {
					cout << '0';
				}
				else {
					cout << '-';
				}
			}
		}
		cout << '\n';
	}
}