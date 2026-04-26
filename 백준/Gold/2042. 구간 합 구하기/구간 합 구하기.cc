// 2042번 구간 합 구하기 (세그먼트 트리 말고 펜윅트리)
#include<iostream>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;

ll n, m, k;
vector<ll> v, tree;

// query
ll sum(int i) {
	int idx = i;
	ll ans = 0;
	while (idx>0) {
		ans += tree[idx];
		idx -= idx & -idx;
	}
	return ans;
}

void update(int i, ll diff) {
	int idx = i;
	while (idx <= tree.size()) {
		tree[idx] += diff; idx += idx & -idx;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	v.resize(n + 5);
	tree.resize(n + 5);

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		update(i, v[i]);
	}

	m += k;

	while (m--) {
		ll a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			long long diff = c - v[b];
			v[b] = c;
			update(b, diff);
		}
		else {
			cout << sum(c) - sum(b - 1) << '\n';
		}
	}


}