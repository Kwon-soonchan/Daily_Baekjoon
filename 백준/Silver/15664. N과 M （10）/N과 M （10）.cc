// 15664번 N과M(10)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v;
vector<int> comb;

void findComb(int start, int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << comb[i] << " ";
		}
		cout << "\n";
		return;
	}

	int last = -1;
	for (int i = start; i < n; i++) {
		if (last == v[i]) {
			continue;
		}

		comb.push_back(v[i]);
		last = v[i];

		findComb(i + 1, depth + 1);
		comb.pop_back();
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	findComb(0, 0);

	return 0;
}