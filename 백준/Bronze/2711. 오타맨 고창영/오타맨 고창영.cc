#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	string list[] = { "0" };

	for (int i = 0; i < T; i++) {
		int n;
		string word;
		cin >> n >> word;
		word.erase(word.begin() + (n - 1));
		cout << word << '\n';
	}
}
