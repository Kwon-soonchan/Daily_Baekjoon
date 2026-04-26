#include <iostream>
#include <queue>
using namespace std;

priority_queue <int> pq;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x == 0) {
			if (!pq.empty()) {
				cout << pq.top() << '\n';
				pq.pop();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else {
			for (int j = 0; j < x; j++) {
				int a;
				cin >> a;
				pq.push(a);
			}
		}
	}
}
