#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	vector <int> list;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m;
		list.push_back(m);
	}
	sort(list.begin(), list.end());
	reverse(list.begin(), list.end());
	for (int j = 0; j < n; j++) {
		cout << list[j] << "\n";
	}
}