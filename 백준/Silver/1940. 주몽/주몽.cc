// 1940번 주몽
#include<iostream>
using namespace std;

int A[15'001];

int main() {
	int N, M;
	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int count = 0;

	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (A[i] + A[j] == M) {
				count++;
			}
		}
	}

	cout << count;

}