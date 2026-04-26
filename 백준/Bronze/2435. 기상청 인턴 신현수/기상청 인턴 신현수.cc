// 2435번 기상청 인턴 신현수
#include<iostream>
#include<algorithm>
using namespace std;

int A[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A[i] = a;
	}

	int C = 0;
	int sum = -2e9;

	for (int i = 0; i < K; i++) {
		C += A[i];
	}

	sum = C;

	int s = 0;
	int e = K - 1;

	while (e != N -1) {
		s++;
		e++;
		C -= A[s - 1];
		C += A[e];

		sum = max(C, sum);
	}

	cout << sum;
}