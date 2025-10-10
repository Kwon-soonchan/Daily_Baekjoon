#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<sstream>
#include<time.h>
#include<vector>
using namespace std;

// 재귀함수
void hanoi(int n, int start, int middle, int end) {
	if (n == 1) {
		// 경로를 벡터에 저장하는 대신 바로 출력
		cout << start << " " << end << "\n";
		return;
	}
	hanoi(n - 1, start, end, middle);
	// 가장 큰 원반을 옮기는 경로를 바로 출력
	cout << start << " " << end << "\n";
	hanoi(n - 1, middle, start, end);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;

	// 이동 횟수는 2^N - 1 공식으로 계산
	cout << (1LL << N) - 1 << "\n"; // 비트 시프트 연산이 pow 함수보다 훨씬 빠릅니다.

	// N이 20 이하일 때만 경로를 출력
	if (N <= 20) {
		hanoi(N, 1, 2, 3);
	}

	return 0;
}