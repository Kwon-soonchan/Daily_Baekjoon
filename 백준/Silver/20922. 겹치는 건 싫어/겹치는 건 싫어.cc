// 20922번 겹치는 건 싫어
#include<iostream>
#include<algorithm>
using namespace std;

int A[200'001];
int B[100'001] = { 0 };

int main() {
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int s = 0;
	int e = 0;
	int cur_len = 0;
	int max_len = 0;

	while (e < N) {
		B[A[e]]++;

		while (B[A[e]] > K) {
			B[A[s]]--;
			s++;
		}

		max_len = max(max_len, e - s + 1);
		e++;
	}
	
	cout << max_len;
}
