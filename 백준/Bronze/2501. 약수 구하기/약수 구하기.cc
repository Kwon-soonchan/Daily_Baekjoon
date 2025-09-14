#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> factor;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			factor.push_back(i);
		}
	}

	cout << factor[k-1] << endl;
}