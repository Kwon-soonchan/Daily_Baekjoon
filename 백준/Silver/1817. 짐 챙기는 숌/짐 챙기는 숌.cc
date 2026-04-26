// 1817번 짐 챙기는 숌
#include<iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	int sum = 0;
	int bag = 0;

	for (int i = 0; i < N; i++) {
		int book;
		cin >> book;

		sum += book;

		if (i == 0) {
			bag++;
		}

		if (sum > M) {
			sum = book;
			bag++;
		}
		else {
			continue;
		}
	}

	cout << bag;
}