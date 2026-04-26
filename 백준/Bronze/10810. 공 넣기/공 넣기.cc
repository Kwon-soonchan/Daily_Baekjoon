// 10810번 공 넣기
#include<iostream>
using namespace std;

int arr[100];

int main() {
	int N, M;
	cin >> N >> M;

	for (int m = 0; m < M; m++) {
		int i, j, k;
		cin >> i >> j >> k;

		for (int a = i; a <= j; a++) {
			arr[a] = k;
		}
	}

	for (int b = 1; b <= N; b++) {
		cout << arr[b] << ' ';
	}

}