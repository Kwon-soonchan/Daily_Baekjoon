// 1676번 팩토리얼 0의 개수
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 0;

	while (n >= 5) {
		cnt += n / 5;
		n /= 5;
	}

	cout << cnt;

	return 0;
}