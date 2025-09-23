#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	set<int> v1;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v1.insert(a);
	}

	int m;
	cin >> m;
	vector<int> v2(m);
	for (int i = 0; i < m; i++) {
		cin >> v2[i];
	}

	vector<int> v3(m);
	for (int i = 0; i < m; i++) {
		if (v1.find(v2[i]) != v1.end()) {
			v3[i] = 1;
		}
		else {
			v3[i] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		cout << v3[i] << " ";
	}
}