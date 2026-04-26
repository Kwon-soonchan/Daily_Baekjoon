#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a;
	int num[3];
	for (int i = 0; i < 3; i++) {
		cin >> a;
		num[i] = a;
	}
	sort(num, num + 3);

	cout << num[1];
}