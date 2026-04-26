// 1436번 영화감독 숌
#include<iostream>
#include<string>
using namespace std;

int search666(int cur) {
	do {
		cur++;
	} while (to_string(cur).find("666") == string::npos);
	return cur;
}

int find666(int n) {
	int cur = 665;
	for (int i = 0; i < n; i++) {
		cur = search666(cur);
	}

	return cur;
}

int main() {
	int n;
	cin >> n;

	int result = find666(n);
	cout << result;
}