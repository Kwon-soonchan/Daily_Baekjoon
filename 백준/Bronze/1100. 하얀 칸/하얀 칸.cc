#include <iostream>
#include <string>
using namespace std;

int main() {
	int count = 0;
	string board;

	for (int i = 0; i < 8; i++) {
		cin >> board;
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0 && j % 2 == 0 && board[j] == 'F') {
				count++;
			}
			else if (i % 2 != 0 && j % 2 != 0 && board[j] == 'F') {
				count++;
			}
		}
	}
	cout << count;
}