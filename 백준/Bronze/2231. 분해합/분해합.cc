// 2231번 분해합
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int	compare = i;
		int temp = i;

		while (temp > 0) {
			compare += temp % 10;
			temp /= 10;
		}

		if (compare == n) {
			cout << i;
			
			return 0;
		}
	}

	cout << 0;
}