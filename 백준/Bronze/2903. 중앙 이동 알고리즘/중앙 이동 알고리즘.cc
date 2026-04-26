#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int dot_width = 2;
	for (int i = 0; i < n; i++) {
		dot_width = (dot_width * 2) - 1;
	}
	cout << dot_width * dot_width << endl;
}