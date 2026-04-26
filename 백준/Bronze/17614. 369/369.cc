// 17614번 369
#include<iostream>
#include<string>
using namespace std;

int main() {
	
	int n;
	cin >> n;

	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		string s = to_string(i);

		for (char c : s) {
			if (c == '3' || c == '6' || c == '9') {
				cnt++;
			}
		}

	}
	cout << cnt;
}