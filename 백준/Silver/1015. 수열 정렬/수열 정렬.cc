#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	vector<pair<int, int>> B;
	for (int i = 0; i < n; i++) {
		B.push_back({ A[i], i });
	}
	stable_sort(B.begin(), B.end());

	vector<int> result(n);
	for (int i = 0; i < n; i++) {
		result[B[i].second] = i;
	}
	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
}