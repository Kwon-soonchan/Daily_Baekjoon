#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	vector<int> v2(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v2[i] = v[i];
	}
	sort(v2.begin(), v2.end());
	next_permutation(v.begin(), v.end());

	if (v == v2) {
		cout << -1;
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
	}
	
	return 0;
}