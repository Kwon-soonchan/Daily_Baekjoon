#include <iostream>
using namespace std;

long long list[100'001];

int main() {
	long long n, k;
	long long start = 0;
	long long end = 0;
	long long count = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	cin >> k;

	while (true) {
		long long sum = 0;

		if (end > n - 1) {
			break;
		}

		if (start == end) {
			if (list[start] > k) {
				count += (n - end);
				start++;
			}
			end++;
		}
		else {
			for (int i = start; i <= end; i++) {
				sum += list[i];
			}
			if (sum > k) {
				count += (n - end);
				start++;
			}
			else if (sum <= k) {
				end++;
			}
		}
	}
	cout << count;
}