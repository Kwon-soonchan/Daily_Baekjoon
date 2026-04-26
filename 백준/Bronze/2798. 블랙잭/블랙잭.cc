// 2798번 블랙잭
#include<iostream>
#include<algorithm>
using namespace std;

int arr[101];

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		arr[i] = n;
	}

	sort(arr, arr + N);
	int subArr[101];
	fill(subArr, subArr + N, 1);

	for (int i = 0; i < 3; i++) {
		subArr[i] = 0;
	}

	int max_sum = 0;

	do {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (subArr[i] == 0) {
				sum += subArr[i] + arr[i];
				if (sum <= M) {
					max_sum = max(max_sum, sum);
				}
			}
		}
	} while (next_permutation(subArr, subArr + N));

	cout << max_sum;
}
