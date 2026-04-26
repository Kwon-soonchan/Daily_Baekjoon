// 2230번 수 고르기
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int N;
		cin >> N;
		v.push_back(N);
	}
	sort(v.begin(), v.end());
	int st = 0, en = 0;
	int a = 2e9;

	while (st < n && en < n) {
		int result = v[en] - v[st];

		if (v[en] - v[st] >= m) {
			a = min(a, result);
			st++;
		}
		else {
			en++;
		}
	}
	cout << a;

}