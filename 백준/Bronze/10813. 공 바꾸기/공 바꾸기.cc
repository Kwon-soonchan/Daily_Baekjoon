// 10813번 공 바꾸기
#include<iostream>
using namespace std;

int arr[100];

int main() {
	int N, M;
	cin >> N >> M;

	for (int a = 1; a <= N; a++) {
		arr[a] = a;
	}

	for (int a = 1; a <= M; a++) {
		int i, j, b;
		cin >> i >> j;

		b = arr[i];
		arr[i] = arr[j];
		arr[j] = b;
	}

	for (int a = 1; a <= N; a++) {
		cout << arr[a] << ' ';
	}
}