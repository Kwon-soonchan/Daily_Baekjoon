#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	cin >> n;

	char arr[11][21];

	string s;
	cin >> s;

	int row = s.length() / n;



	for (int i = 0; i < row; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = s[i * n + j];
			}
		}
		else {
			for (int j = n; j > 0; j--) {
				arr[i][n - j] = s[i * n + j - 1];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < row; j++) {
			cout << arr[j][i];
		}
	}
}