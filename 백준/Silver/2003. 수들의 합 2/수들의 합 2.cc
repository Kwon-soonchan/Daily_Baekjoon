// 2003번 수들의 합2
#include <iostream>
using namespace std;
int list[10'001];

int main() {
	int n, m;
	int count = 0;
	int start = 0;
	int end = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	while (true) {
		int sum = 0;

		if (end > n - 1) {
			break;
		}

		if (start == end) {
			if (list[start] == m) {
				count++;
			}
			end++;
		}
		else {
			for (int i = start; i <= end; i++) {
				sum += list[i];
			}
			if (sum == m) {
				count++;
				start++;
			}
			else if (sum < m) {
				end++;
			}
			else if (sum > m) {
				start++;
			}
		}
	}
	cout << count;
}