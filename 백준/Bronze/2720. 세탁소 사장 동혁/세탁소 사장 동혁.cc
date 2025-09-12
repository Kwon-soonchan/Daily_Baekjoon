#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int money;
		int quarter = 0, dime = 0, nickel = 0, penny = 0;
		cin >> money;

		quarter = money / 25;
		money %= 25;
		dime = money / 10;
		money %= 10;
		nickel = money / 5;
		money %= 5;
		penny = money / 1;

		cout << quarter << " " << dime << " " << nickel << " " << penny << endl;
	}
}