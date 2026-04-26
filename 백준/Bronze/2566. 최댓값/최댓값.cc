// 2566번 최댓값
#include<iostream>
using namespace std;

int main() {
	int max = 0;
	int r = 1, c = 1;

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			int n;
			cin >> n;
			if (n > max) {
				max = n;
				r = i;
				c = j;
			}
		}
	}
	cout << max << '\n' << r << ' ' << c;
}