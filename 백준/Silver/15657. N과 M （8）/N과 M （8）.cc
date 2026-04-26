#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> v(n);
	vector<int> v2(n+m-1, 1);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	
	for (int i = 0; i < m; i++) {
		v2[i] = 0;
	}

	do {
		int idx = 0;
		vector<int> v3;
		for (int i = 0; i < v2.size(); i++) {
			if (v2[i] == 0) {
				v3.push_back(v[idx]);
			} 
			else {
				idx++;
			}
		}
		for (int i : v3) {
			cout << i << " ";
		}
		cout << "\n";
	} while (next_permutation(v2.begin(), v2.end()));
}