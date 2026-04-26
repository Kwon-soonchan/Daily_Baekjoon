#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int a;
	int min;
	int max;
	vector <int> list;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		list.push_back(a);
	}
	min = list[0];
	max = list[0];
	for (int j : list) {
		if (min > j) {
			min = j;
		}
		if (max < j) {
			max = j;
		}
	}
	cout << min << " " << max;
}