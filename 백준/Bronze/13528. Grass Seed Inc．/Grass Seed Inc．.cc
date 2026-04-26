#include<iostream>
using namespace std;

int main() {
	double c, l;
	cin >> c >> l;

	double sum = 0;

	for (int i = 0; i < l; i++) {
		double w, h;
		cin >> w >> h;
		sum += w * h * c;
	}

	cout << fixed;
	cout.precision(7);
	cout << sum << endl;
}