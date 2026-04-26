// 1966번 프린터 큐
#include<iostream>
#include<queue>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		queue<pair<int, int>> q;
		int pri[10] = { 0 };

		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			q.push({ i,p });
			pri[p]++;
		}

		int count = 0;

		while (!q.empty()) {
			auto cur = q.front();
			q.pop();

			bool up = false;

			for (int i = cur.second + 1; i <= 9; i++) {
				if (pri[i] > 0) {
					up = true;
					break;
				}
			}
			if (up) {
				q.push(cur);
			}
			else {
				count++;
				pri[cur.second]--;

				if (cur.first == m) {
					cout << count << '\n';
					break;
				}
			}
		}
	}
}