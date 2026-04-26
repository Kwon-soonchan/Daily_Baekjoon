// 2243번 사탕상자
#include<iostream>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;

ll n;
vector<ll> tree(1000001, 0);

// query
ll sum(int i) {
	int idx = i;
	ll ans = 0;
	while (idx > 0) {
		ans += tree[idx];
		idx -= idx & -idx;
	}
	return ans;
}

void update(int idx, ll diff) {
	while (idx <= tree.size()) {
		tree[idx] += diff;
		idx += idx & -idx;
	}
}

int find(ll grade) {
	int st = 1;
	int en = tree.size();
	int result = 0;

	while (st <= en) {
		int mid = (st + en) / 2;

		if (sum(mid) >= grade) {
			result = mid;
			en = mid - 1;
		}
		else {
			st = mid + 1;
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;

		if (a == 1) {
			ll b;
			cin >> b;
			int flavor = find(b);
			cout << flavor << '\n';
			update(flavor, -1);
		}
		else {
			int b;
			ll c;
			cin >> b >> c;
			update(b, c);
		}
	}

}