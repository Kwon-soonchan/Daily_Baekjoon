#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, dasom;
	cin >> n >> dasom;

	vector<int> v;
	int m;

	for (int i = 0; i < n-1; i++) {
		cin >> m;
		v.push_back(m);
	}

	sort(v.begin(), v.end(), greater<int>());
	int cnt = 0;
	bool check = false;

	while (true) {
		if(v.empty() || dasom > v[0]) {
			check = true;
			break;
		}
		if (dasom <= v[0]) {
			v[0]--;
			dasom++;
			cnt++;
			sort(v.begin(), v.end(), greater<int>());
		}
	}
	cout << cnt << endl;
}