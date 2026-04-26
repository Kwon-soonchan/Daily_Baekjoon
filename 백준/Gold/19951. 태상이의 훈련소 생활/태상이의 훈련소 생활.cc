#include<iostream>
using namespace std;

void sol(int* ground, int N, int M, int* arr, int* sum) {
	int A, B, K;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> K;
		arr[A] += K;
		arr[B + 1] -= K;
	}
	for (int i = 1; i <= N; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}
	for (int i = 1; i <= N; i++) {
		ground[i] += sum[i];
		cout << ground[i] << ' ';
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	int* ground = new int[N + 1];
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		ground[i] = num;
	}

	int* sum = new int[N + 2] { 0, };
	int* arr = new int[N + 2] { 0, };
	sol(ground, N, M, arr, sum);

	//system("pause");
	return 0;
}