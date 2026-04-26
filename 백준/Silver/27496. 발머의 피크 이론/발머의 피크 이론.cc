// 27496번 발머의 피크 이론
#include<iostream>
using namespace std;

int A[1'000'001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, L;
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A[i] = a;
	}

	int C = 0;
	int cnt = 0;

	for (int i = 0; i < L; i++) {
		if (129 <= C && C <= 138) {
			cnt++;
		}
		C += A[i];
	}

	int s = 0;
	int e = L - 1;

	while (e != N) {
		if (129 <= C && C <= 138) {
			cnt++;
		}
		s++;
		e++;
		C -= A[s - 1];
		C += A[e];
	}

	cout << cnt;
}