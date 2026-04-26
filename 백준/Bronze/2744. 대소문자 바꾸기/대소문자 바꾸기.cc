#include <iostream>
#include <string>
using namespace std;

int main() {
	string word;
	cin >> word;
	for (int i = 0; i < word.size(); i++) { 
		if ('A' <= word[i] && 'Z' >= word[i]) {
			word[i] += 32;
		}
		else if ('a' <= word[i] && 'z' >= word[i]) {
			word[i] -= 32;
		}
	}
	cout << word;
}
