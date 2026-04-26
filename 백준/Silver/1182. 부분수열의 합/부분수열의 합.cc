#include<iostream>
#include<vector>
using namespace std;

int n, s;
int cnt = 0;
vector<int> arr;

void dfs(int idx, int sum) {
	if (idx == n) {
		if (sum == s) {
			cnt++;
		}
		return;
	}
	dfs(idx + 1, sum + arr[idx]);
	dfs(idx + 1, sum);
}

int main() {
	cin >> n >> s;
	arr.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dfs(0, 0);

	if (s == 0) {
		cnt--; // 공집합을 제외하기 위해서
	}
	cout << cnt << endl;


	// 이건 연속된 부분 수열의 합을 구하는 문제 - O(N^3)
	//vector<int> arr(n);
	//for (int i = 0; i < n; i++) {
	//	cin >> arr[i];
	//}

	//int cnt = 0;
	//int sum = 0;
	//for (int i = 0; i < n; i++) {
	//	for (int j = n-1; j >= i; j--) {
	//		for (int k = i; k <= j; k++) {
	//			sum += arr[k];
	//		}
	//		if (sum == s) {
	//			cnt++;
	//		}
	//		sum = 0;
	//	}

	//}
	//cout << cnt << endl;
}