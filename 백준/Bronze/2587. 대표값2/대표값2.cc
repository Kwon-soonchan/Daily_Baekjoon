#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	vector<int> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	v.push_back(e);
	sort(v.begin(), v.end());

	int ave = (a + b + c + d + e) / 5;
	int mid = v[2];

	cout << ave << endl << mid;
}