// 13422번 도둑
#include<iostream>
#include<vector>
using namespace std;

vector<long long> v;
vector<long long> sum_list;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n, m, k;
		cin >> n >> m >> k;

		v.clear();

		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			v.push_back(a);
		}

		long long sum = 0;
		int count = 0;
		sum_list.clear();

		for (int i = 0; i < m; i++) {
			sum += v[i];
		}

		for (int i = 0; i < n; i++) {
			sum_list.push_back(sum);
			int st = i % n;
			int en = (st + m) % n;
			sum = sum - v[st] + v[en];
		}

		for (int i : sum_list) {
			if (n == m) {
				if (i < k) {
					count++;
					break;
				}
			}
			else {
				if (i < k) {
					count++;
				}
			}
		}
		cout << count << '\n';
	}
}