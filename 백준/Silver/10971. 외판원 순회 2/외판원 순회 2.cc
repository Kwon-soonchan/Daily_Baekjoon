#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<int>> arr(n, vector<int>(n));
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		v[i] = i;
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int min_cost = 1e9;
	do {
		int cost = 0;
		bool valid = true;
		for (int i = 0; i < n - 1; i++) {
			if(valid && arr[v[i]][v[i + 1]] == 0) {
				valid = false;
				break;
			}
			cost += arr[v[i]][v[i + 1]];
		}
		if (valid && arr[v[n - 1]][v[0]] != 0) {
			cost += arr[v[n - 1]][v[0]];
			min_cost = min(min_cost, cost);
		}
	} while (next_permutation(v.begin(), v.end()));

	cout << min_cost << endl;
}