#include<iostream>
#include<vector>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	vector<int> v;
	v.push_back(x);
	v.push_back(y);
	v.push_back(w - x);
	v.push_back(h - y);

	int min_length = 1000;
	for (int i = 0; i < 4; i++) {
		if (min_length > v[i]) {
			min_length = v[i];
		}
	}
	cout << min_length;
}