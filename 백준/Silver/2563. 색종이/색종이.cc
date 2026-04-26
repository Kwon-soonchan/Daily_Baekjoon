#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int cnt = 0;
	int paper[101][101] = { 0, };

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		for (int j = x; j < x + 10; j++) {
			for (int k = y; k < y + 10; k++) {
				paper[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (paper[i][j] == 1) {
				cnt++;
			}
		}
	}

	cout << cnt << endl;
}