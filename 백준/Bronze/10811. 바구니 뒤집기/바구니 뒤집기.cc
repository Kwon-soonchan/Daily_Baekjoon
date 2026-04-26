// 10811번 바구니 뒤집기
#include<iostream>
#include<algorithm>
using namespace std;

int arr[100];

int main() {
	int N, M;
	cin >> N >> M;

	for (int a = 1; a <= N; a++) {
		arr[a] = a;
	}

	for (int a = 1; a <= M; a++) {
		int i, j;
		cin >> i >> j;
		reverse(arr + i, arr + j+1);
	}

	for (int a = 1; a <= N; a++) {
		cout << arr[a] << ' ';
	}
}