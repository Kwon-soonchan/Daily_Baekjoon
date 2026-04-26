#include <iostream>
using namespace std;

int n;
int zero_cnt = 0, plus_cnt = 0, minus_cnt = 0;
int board[2188][2188];

bool check_cut(int n, int x, int y) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (board[i][j] != board[x][y]) {
				return true;
			}
		}
	}
	return false;
}

void paper_cut(int n, int x, int y) {
	int one_third = n / 3;
	if (check_cut(n, x, y)) {
		// 파트 반복
		paper_cut(one_third, x, y);
		paper_cut(one_third, x + one_third, y);
		paper_cut(one_third, x + one_third * 2, y);
		paper_cut(one_third, x, y + one_third);
		paper_cut(one_third, x + one_third, y + one_third);
		paper_cut(one_third, x + one_third * 2, y + one_third);
		paper_cut(one_third, x, y + one_third * 2);
		paper_cut(one_third, x + one_third, y + one_third * 2);
		paper_cut(one_third, x + one_third * 2, y + one_third * 2);
	}
	else {
		if (board[x][y] == 0) {
			zero_cnt++;
		}
		else if (board[x][y] == 1) {
			plus_cnt++;
		}
		else if (board[x][y] == -1) {
			minus_cnt++;
		}
	}
}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	paper_cut(n, 0, 0);

	cout << minus_cnt << '\n' << zero_cnt << '\n' << plus_cnt;
}