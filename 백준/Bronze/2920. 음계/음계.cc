// 2920번 음계
#include<iostream>
using namespace std;

int main() {
	int dajangjo[8];
	
	for (int i = 0; i < 8; i++) {
		cin >> dajangjo[i];
	}

	if (dajangjo[0] == 1 && dajangjo[1] == 2 && dajangjo[2] == 3 && dajangjo[3] == 4 &&
		dajangjo[4] == 5 && dajangjo[5] == 6 && dajangjo[6] == 7 && dajangjo[7] == 8) {
		cout << "ascending";
	}
	else if (dajangjo[0] == 8 && dajangjo[1] == 7 && dajangjo[2] == 6 && dajangjo[3] == 5 &&
		dajangjo[4] == 4 && dajangjo[5] == 3 && dajangjo[6] == 2 && dajangjo[7] == 1) {
		cout << "descending";
	}
	else {
		cout << "mixed";
	}

}