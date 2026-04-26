#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;


ll n, m;
ll ans = 0;
ll sum = 0;
vector<int> v;

void Binary_search(ll left, ll right, ll target) {
	while (left <= right) {
		ll mid = left + (right - left) / 2;
		ll cnt = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] > mid) {
				cnt += v[i] - mid;
			}
		}
		if (cnt >= target) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		v.push_back(x);
	}

	ll left = 1;
	ll right = *max_element(v.begin(), v.end());

	Binary_search(left, right, m);

	cout << ans << endl;
}