// 29718번 줄줄이 박수
#include<iostream>
#include<algorithm>
using namespace std;

int A[2000][2000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a;
			cin >> a;
			A[i][j] = a;
		}
	}

	int L;
	cin >> L;

	int cur_clap = 0;
	int max_clap = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < L; j++) {
			cur_clap += A[i][j];
		}
		max_clap = max(cur_clap, max_clap);
	}

	int s = 0;
	int e = L - 1;

	while (e != M) {
		s++;
		e++;
		for (int i = 0; i < N; i++) {
			cur_clap += A[i][e];
			cur_clap -= A[i][s-1];
		}
		max_clap = max(cur_clap, max_clap);
	}

	cout << max_clap;
}