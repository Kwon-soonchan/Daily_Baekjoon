// 2884번 알람 시계
#include<iostream>
using namespace std;

int main() {
	int H, M;
	cin >> H >> M;

	if (M >= 45) {
		M = M - 45;
	}
	else {
		if (H >= 1) {
			H--;
			M = (60 + M) - 45;
		}
		else {
			H = 23;
			M = (60 + M) - 45;
		}

	}

	cout << H << ' ' << M;
}