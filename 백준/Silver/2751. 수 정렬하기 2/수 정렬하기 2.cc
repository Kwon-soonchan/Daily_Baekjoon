// 2751번 수 정렬하기 2
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		cout << v[i] << '\n';
	}
}