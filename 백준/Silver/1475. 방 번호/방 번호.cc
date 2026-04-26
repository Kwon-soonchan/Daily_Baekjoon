#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int main() {
	string s;
	cin >> s;

	vector<int> v(10, 0);
	for (char c : s) {
		v[c - '0'] += 1;
	}

	int max_cnt = 0;
	int sixnine = v[6] + v[9];
	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) {
			continue;
		}
		max_cnt = max(max_cnt, v[i]);
	}

	cout << max(max_cnt, (sixnine + 1) / 2);
}