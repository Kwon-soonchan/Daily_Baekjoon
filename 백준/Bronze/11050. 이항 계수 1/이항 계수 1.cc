// 11050번 이항 계수 1
#include<iostream>
using namespace std;

int ihang(int n, int k) {
	int result = 1;

	for (int i = 0; i < k; ++i) {
		result = result * (n - i);
		result = result / (i + 1);
	}

	return result;
}

int main() {
	int n, k;
	cin >> n >> k;

	cout << ihang(n, k);
}