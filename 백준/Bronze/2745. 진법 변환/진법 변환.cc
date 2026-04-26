#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int num[26] = { 10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35 };

int main() {
	string n; // 수
	int b; // 진법
	cin >> n >> b;

	int ten = 0;
	for (int i = n.length(); i > 0; i--) {
		int number;
		if (isdigit(n[n.length() - i])) {
			number = n[n.length() - i] - '0';
		}
		else {
			number = num[n[n.length() - i] - 'A'];
		}
		
		ten += number * pow(b, i - 1);
	}

	cout << ten << endl;
}