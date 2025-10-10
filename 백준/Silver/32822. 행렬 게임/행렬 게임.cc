#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> hoon(n, vector<int>(n));
	vector<vector<int>> chan(n, vector<int>(n));

	//훈이꺼
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> hoon[i][j];
		}
	}
	//찬이꺼
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> chan[i][j];
		}
	}

	// 1. 각 열(column)에서 얻을 수 있는 최대 점수를 미리 계산 (O(N^2))
	vector<int> max_diffs_per_column(n);
	for (int j = 0; j < n; j++) { // j: 열 번호
		int max_val_in_col = 0;
		for (int i = 0; i < n; i++) { // i: 행 번호
			max_val_in_col = max(max_val_in_col, abs(hoon[i][j] - chan[i][j]));
		}
		max_diffs_per_column[j] = max_val_in_col;
	}

	// 2. M 라운드 동안 미리 계산된 값을 더하기만 함 (O(M))
	long long result = 0;
	for (int k = 0; k < m; k++) {
		int x;
		cin >> x;
		result += max_diffs_per_column[x - 1]; // 1-based index를 0-based로
	}

	// try3
	//vector<vector<int>> hc(n, vector<int>(n)); // hc 행렬 생성 및 크기 할당
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		hc[i][j] = abs(hoon[i][j] - chan[i][j]); // 각 원소의 차이를 계산하여 저장
	//	}
	//}



	// try1
	//int result = 0;
	//for (int beta : round) {
	//	int max_diff = 0;
	//	for (int i = 0; i < n; i++) {
	//		max_diff = max(max_diff, abs(hoon[i][beta] - chan[i][beta]));
	//	}
	//	result += max_diff;
	//}

	// try2
	//int result = 0;
	//for (int i = 0; i < n; i++) {
	//	int max_diff = 0;
	//	for (int j = 0; j < n; j++) {
	//		max_diff = (max_diff, abs(hoon[i][j] - chan[i][j]));
	//	}
	//	result += max_diff;
	//}

	cout << result;
}