#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<char> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	vector<int> v2(m, 1);
	for (int i = 0; i < n; i++) {
		v2[i] = 0;
	}

	do {
		string s = "";
		int moum = 0;
		int jaum = 0;
		for (int i = 0; i < m; i++) {
			if (v2[i] == 0) {
				s += v[i];
				if(v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
					moum++;
				} else {
					jaum++;
				}
			}
		}
		if (moum >= 1 && jaum >= 2) {
			cout << s << "\n";
		}
	} while (next_permutation(v2.begin(), v2.end()));
}