#include <iostream>
using namespace std;

int n, blue_cnt = 0, white_cnt = 0;
int** board = new int* [n];

bool check_cut(int num, int x, int y) { // 잘라야 하는지 확인
	for (int i = x; i < x + num; i++) {
		for (int j = y; j < y + num; j++) {
			if (board[i][j] != board[x][y]) { // 중간에 다른 색이 나오면
				return true; // 잘라야한다
			}
		}
	}
	return false;
}

void make_paper(int num, int x, int y) {
	int half = num / 2;
	if (check_cut(num, x, y)) { // 잘라야 하는 색종이면
		// 파트별로 반복
		make_paper(half, x, y);
		make_paper(half, x, y + half);
		make_paper(half, x + half, y);
		make_paper(half, x + half, y + half);
	}
	else {
		if (board[x][y] == 1) { // 1인 경우 파란색
			blue_cnt++;
		}
		else { // 0인 경우 흰색
			white_cnt++;
		}
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		board[i] = new int[n];
		fill_n(board[i], n, 0);
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	make_paper(n, 0, 0);

	cout << white_cnt << '\n' << blue_cnt;
}