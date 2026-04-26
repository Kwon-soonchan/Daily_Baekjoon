// 18110번 solved.ac
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> v;

int main() {
	int n, n2;
	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}

	n2 = round(n * 0.15);

	for (int i = 0; i < n; i++) {
		int N;
		cin >> N;
		v.push_back(N);
	}

	sort(v.begin(), v.end());

	v.erase(v.begin(), v.begin() + n2);
	v.erase(v.end() - n2, v.end());

	double sum = 0;

	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}
	cout << round(sum / v.size());
}