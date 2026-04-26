// 20673번 Covid-19
#include<iostream>
using namespace std;

int main() {
	int p, q;
	cin >> p;
	cin >> q;

	if (p <= 50 && q <= 10) {
		cout << "White";
	}
	else if (q > 30) {
		cout << "Red";
	}
	else {
		cout << "Yellow";
	}
}