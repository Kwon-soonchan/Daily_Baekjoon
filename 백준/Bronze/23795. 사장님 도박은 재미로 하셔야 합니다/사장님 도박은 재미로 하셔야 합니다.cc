#include<iostream>
using namespace std;


int main() {
	int sum = 0;

	while (true) {
		int n;
		cin >> n;
		if (n == -1) {
			break;
		}
		else {
			sum += n;
		}
	}
	cout << sum << endl;
}