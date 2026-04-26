// 알쿡 겨울학기 코테 5번 
// 2864번 5와 6의 차이
#include<iostream>
#include<string>
using namespace std;

char list_a[7];
char list_b[7];

int main() {
	string a, b, a_result, b_result;
	cin >> a >> b;

	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '6') {
			a[i] = '5';
		}
		list_a[i] = a[i];
	}
	for (int i = 0; i < b.length(); i++) {
		if (b[i] == '6') {
			b[i] = '5';
		}
		list_b[i] = b[i];
	}
	for (int i = 0; i < a.length(); i++) {
		a_result += list_a[i];
	}
	for (int i = 0; i < b.length(); i++) {
		b_result += list_b[i];
	}
	cout << stoi(a_result) + stoi(b_result);

	a_result.clear();
	b_result.clear();
	cout << ' ';

	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '5') {
			a[i] = '6';
		}
		list_a[i] = a[i];
	}
	for (int i = 0; i < b.length(); i++) {
		if (b[i] == '5') {
			b[i] = '6';
		}
		list_b[i] = b[i];
	}
	for (int i = 0; i < a.length(); i++) {
		a_result += list_a[i];
	}
	for (int i = 0; i < b.length(); i++) {
		b_result += list_b[i];
	}
	cout << stoi(a_result) + stoi(b_result);

}