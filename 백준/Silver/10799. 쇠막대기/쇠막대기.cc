#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;

	int cnt = 0;
	int result = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ')' && s[i - 1] == '(') {
			result += cnt;
		}
		else if (s[i] == '(' && s[i + 1] == ')') {
			continue;
		}
		else if (s[i] == '(') {
			cnt++;
		}
		else if (s[i] == ')') {
			result++;
			cnt--;
		}
	}
	cout << result << endl;
}