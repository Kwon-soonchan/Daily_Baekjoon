#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		int count = 0;
		int result = 0;
		for (char j : s) {
			if (j == 'O') {
				count++;
			}
			else if (j == 'X') {
				count = 0;
			}
			result += count;
		}
		cout << result << '\n';
	}
}