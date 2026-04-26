#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int k, n;
ll ans = 0;
vector<ll> v;

void Binary_search(ll left, ll right, ll n, vector<ll>& v) {
	while (left <= right) {
		ll mid = left + (right - left) / 2;
		ll cnt = 0;

		for (int i = 0; i < k; i++) {
			cnt += v[i] / mid;
		}
		if (cnt < n) {
			right = mid - 1;
		}
		else {
			ans = mid;
			left = mid + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		ll x;
		cin >> x;
		v.push_back(x);
	}

	ll left = 1;
	ll right = *max_element(v.begin(), v.end());

	Binary_search(left, right, n, v);
	cout << ans << endl;
}