// 2738번 행렬 덧셈
#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	int A[101][101];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int n;
			cin >> n;
			A[i][j] = n;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int n;
			cin >> n;
			A[i][j] += n;
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
}