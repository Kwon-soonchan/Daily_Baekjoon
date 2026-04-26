//12015번 가장 긴 증가하는 부분 수열 2
#include<iostream>
using namespace std;

int arr[1'000'001];
int lis[1'000'001];

int binary_search(int left, int right, int find) {
	while (left < right) {
		int mid = (left + right) / 2;
		if (lis[mid] < find) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return right;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int i = 0;
	int j = 1;
	lis[0] = arr[0];

	while (i < n) {
		if (lis[j-1] < arr[i]) {
			lis[j] = arr[i];
			j++;
		}
		else {
			int idx = binary_search(0, j, arr[i]);
			lis[idx] = arr[i];
		}
		i++;
	}

	cout << j << '\n';

}