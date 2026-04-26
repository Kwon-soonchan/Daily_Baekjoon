#include <iostream>
#include <string>
using namespace std;

int main() {
	char arr[5][15] = {0,};
	string s;

	for (int i = 0; i < 5; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			arr[i][j] = s[j];
		}
	}
	for (int a = 0; a < 15; a++) {
		for (int b = 0; b < 5; b++) {
			if (!arr[b][a]) {

			}
			else {
				cout << arr[b][a];
			}

		}
	}
}