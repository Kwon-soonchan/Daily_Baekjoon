#include <iostream>
#include <string>
using namespace std;

int main() {
	string hwan, doctor;
	cin >> hwan >> doctor;
	
	if (hwan.length() >= doctor.length()) {
		cout << "go";
	}
	else {
		cout << "no";
	}
}
