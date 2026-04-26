#include<iostream>
using namespace std;

int main() {
	int x;
	cin >> x;
	
	int n = 1;
	int sum = 0;

	while (sum + n < x) {
		sum += n;
		n++;
	}

	int pos = x - sum;

	int up, down;

	if (n % 2 == 0) {
		up = pos;
		down = n - pos + 1;
	}
	else {
		up = n - pos + 1;
		down = pos;
	}

	cout << up << "/" << down << endl;
}