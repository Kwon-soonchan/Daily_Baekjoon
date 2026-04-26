#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> dq(2 * n);
	int front_idx = n;
	int back_idx = n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num == 1) {
			int x;
			cin >> x;
			front_idx--;
			dq[front_idx] = x;
		}
		else if (num == 2) {
			int x;
			cin >> x;
			dq[back_idx] = x;
			back_idx++;
		}
		else if (num == 3) {
			if (front_idx == back_idx) {
				cout << -1 << "\n";
			}
			else {
				cout << dq[front_idx] << "\n";
				front_idx++;
			}
		}
		else if (num == 4) {
			if (front_idx == back_idx) {
				cout << -1 << "\n";
			}
			else {
				cout << dq[back_idx - 1] << "\n";
				back_idx--;
			}
		}
		else if (num == 5) {
			cout << back_idx - front_idx << "\n";
		}
		else if (num == 6) {
			if (front_idx == back_idx) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (num == 7) {
			if (front_idx == back_idx) {
				cout << -1 << "\n";
			}
			else {
				cout << dq[front_idx] << "\n";
			}
		}
		else if (num == 8) {
			if (front_idx == back_idx) {
				cout << -1 << "\n";
			}
			else {
				cout << dq[back_idx - 1] << "\n";
			}
		}
	}
}