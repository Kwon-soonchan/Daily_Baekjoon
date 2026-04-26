// 3085번 사탕 게임
#include<iostream>
#include<algorithm>
using namespace std;

char arr[50][50];

int main() {
	int n;
	cin >> n;

	int cnt = 0;
	int max_cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			// 가로줄 swap
			swap(arr[i][j], arr[i][j + 1]);
			// 가로 비교
			cnt = 1;
			for (int k = 0; k < n - 1; k++) {
				if (arr[i][k] == arr[i][k + 1]) {
					cnt++;
				}
				else {
					max_cnt = max(max_cnt, cnt);
					cnt = 1;
				}
			}
			max_cnt = max(max_cnt, cnt);
			// 세로1 비교
			cnt = 1;
			for (int k = 0; k < n - 1; k++) {
				if (arr[k][j] == arr[k + 1][j]) {
					cnt++;
				}
				else {
					max_cnt = max(max_cnt, cnt);
					cnt = 1;
				}
			}
			max_cnt = max(max_cnt, cnt);
			// 세로2 비교
			if (j + 1 < n) {
				cnt = 1;
				for (int k = 0; k < n - 1; k++) {
					if (arr[k][j + 1] == arr[k + 1][j + 1]) {
						cnt++;
					}
					else {
						max_cnt = max(max_cnt, cnt);
						cnt = 1;
					}
				}
				max_cnt = max(max_cnt, cnt);
			}
			// 원상복구
			swap(arr[i][j], arr[i][j + 1]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			// 세로줄 swap
			swap(arr[j][i], arr[j + 1][i]);
			// 세로 비교
			cnt = 1;
			for (int k = 0; k < n - 1; k++) {
				if (arr[k][i] == arr[k + 1][i]) {
					cnt++;
				}
				else {
					max_cnt = max(max_cnt, cnt);
					cnt = 1;
				}
			}
			max_cnt = max(max_cnt, cnt);
			// 가로1 비교 
			cnt = 1;
			for (int k = 0; k < n - 1; k++) {
				if (arr[j][k] == arr[j][k + 1]) {
					cnt++;
				}
				else {
					max_cnt = max(max_cnt, cnt);
					cnt = 1;
				}
			}
			max_cnt = max(max_cnt, cnt);
			// 가로2 비교
			if (j + 1 < n) {
				cnt = 1;
				for (int k = 0; k < n - 1; k++) {
					if (arr[j + 1][k] == arr[j + 1][k + 1]) {
						cnt++;
					}
					else {
						max_cnt = max(max_cnt, cnt);
						cnt = 1;
					}
				}
				max_cnt = max(max_cnt, cnt);
			}
			// 원상복구
			swap(arr[j][i], arr[j + 1][i]);
		}
	}

	cout << max_cnt;
}
