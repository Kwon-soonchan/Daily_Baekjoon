// 30802번 웰컴 키트
#include<iostream>
using namespace std;

int t_arr[6];

int main() {
	int N, S, M, L, XL, XXL, XXXL, T, P;
	cin >> N;
	for (int i = 0; i < 6; i++) {
		cin >> t_arr[i];
	}
	cin >> T >> P;

	int t_cnt = 0;

	for (int i = 0; i < 6; i++) {
		if (t_arr[i] % T == 0) {
			t_cnt += t_arr[i] / T;
		}
		else {
			t_cnt += t_arr[i] / T + 1;
		}
	}

	cout << t_cnt << '\n';
	cout << N / P << ' ' << N % P;

}