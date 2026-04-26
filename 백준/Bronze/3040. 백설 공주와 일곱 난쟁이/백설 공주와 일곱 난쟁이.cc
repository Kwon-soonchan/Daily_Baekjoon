#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int sum = 0;
	vector <int> v;

	for (int i = 0; i < 9; i++) {
		cin >> n;
		v.push_back(n);
		sum += n;
	}
	sum -= 100;
	for (int j : v) {
		for (int k : v) {
			if (j + k == sum && j != k) {
				v.erase(remove(v.begin(), v.end(), j), v.end());
				v.erase(remove(v.begin(), v.end(), k), v.end());
			}
		}
	}
	for (int l : v) {
		cout << l << "\n";
	}
}