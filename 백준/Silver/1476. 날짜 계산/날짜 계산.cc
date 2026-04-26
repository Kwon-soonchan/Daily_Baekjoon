// 1476번 날짜 계산
#include<iostream>
using namespace std;

int main() {
	// E=15, S=28, M=19 -> 7980까지
	int E, S, M;
	cin >> E >> S >> M;

	for (int i = 1; i <= 7980; i++) {
		int e, s, m;

		if (i % 15 == 0) {
			e = 15;
		}
		else {
			e = i % 15;
		}
		if (i % 28 == 0) {
			s = 28;
		}
		else {
			s = i % 28;
		}
		if (i % 19 == 0) {
			m = 19;
		}
		else {
			m = i % 19;
		}

		if (e == E && s == S && m == M) {
			cout << i;
		}
	}

}