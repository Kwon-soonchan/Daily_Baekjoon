// 5597번 과제 안 내신 분..?
#include<iostream>
using namespace std;

int main() {
	int student[31] = { 0, };

	for (int i = 1; i <= 28; i++) {
		int a;
		cin >> a;
		student[a] = 1;
	}
	for (int i = 1; i <= 30; i++) {
		if (student[i] == 0) {
			cout << i << '\n';
		}
	}
}