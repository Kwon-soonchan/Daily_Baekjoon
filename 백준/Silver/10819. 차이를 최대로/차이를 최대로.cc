#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int diff_max = 0;
	do {
		int diff = 0;

		for(int i = 0; i < n-1; i++) {
			diff += abs(v[i] - v[i + 1]);
		}
		if (diff_max < diff) {
			diff_max = diff;
		}
	} while (next_permutation(v.begin(), v.end()));

	cout << diff_max << endl;
}