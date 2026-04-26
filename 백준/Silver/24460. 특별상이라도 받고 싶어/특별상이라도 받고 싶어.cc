#include <iostream>
#include <algorithm>
using namespace std;

int board[1024][1024];

int solve(int n, int x, int y) {
	int list[4];
	if (n == 2) {
		list[0] = board[x][y];
		list[1] = board[x][y + 1];
		list[2] = board[x + 1][y];
		list[3] = board[x + 1][y + 1];
		sort(list, list + 4);
		return list[1];
	}
	list[0] = solve(n / 2, x, y);
	list[1] = solve(n / 2, x, y + n / 2);
	list[2] = solve(n / 2, x + n / 2, y);
	list[3] = solve(n / 2, x + n / 2, y + n / 2);
	sort(list, list + 4);
	return list[1];
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	if (n == 1) {
		cout << board[0][0];
	}
	else {
		cout << solve(n, 0, 0);
	}

}