#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n,m;
	int sum1 = 0;
	int sum2 = 0;
	cin >> n;
	vector <int> list;

	for (int i = 0; i < n; i++) {
		cin >> m;
		list.push_back(m);
	}
	sort(list.begin(), list.end());
	for (int j = 0; j < n; j++) {
		sum1 += list[j];
		sum2 += sum1;
	}
	cout << sum2;
}