// 2239번 스도쿠
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> board[9];

bool isSafe(int row, int col, int num) {
	for (int d = 0; d < 9; d++) {
		if (board[row][d] == num) {
			return false;
		}
		if (board[d][col] == num) {
			return false;
		}
		if (board[(row / 3) * 3 + d / 3][(col / 3) * 3 + d % 3] == num) {
			return false;
		}
	}
	return true;
}

bool solveSudoku() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] != 0) {
				continue;
			}

			for (int k = 1; k <= 9; k++) {
				if (isSafe(i, j, k)) {
					board[i][j] = k;
					if (solveSudoku()) {
						return true;
					}

					board[i][j] = 0;
				}
			}
			return false;
		}
	}
	return true;
}

int main() {
	for (int i = 0; i < 9; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 9; j++) {
			board[i].push_back(s[j] - '0');
		}
	}

	if (solveSudoku()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j];
			}
			cout << '\n';
		}
	}
}