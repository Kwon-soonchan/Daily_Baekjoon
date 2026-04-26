#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int result1 = 0;
	int result2 = 0;
	int count = 9;
	vector <int> list1, list2;

	for (int i = 0; i < 20; i++) {
		cin >> n;
		if (i < 10) {
			list1.push_back(n);
		}
		else {
			list2.push_back(n);
		}
	}

	sort(list1.begin(), list1.end());
	sort(list2.begin(), list2.end());
	for (int j = 0; j < 3; j++) {
		result1 += list1[count];
		result2 += list2[count];
		count--;
	}
	cout << result1 << " " << result2;
}