#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, b;
	cin >> n >> k >> b;

	vector<int> v(n+1);
	int sum = 0;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = b-1; i < b + k-1; i++) {
		sum += v[i % n];
	}

	cout << sum << endl;
}