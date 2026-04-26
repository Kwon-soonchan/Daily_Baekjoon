// 1701번 Cubeditor
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> getFail(string str) {
	int len = str.length();
	vector<int> fail(len);
	for (int i = 1, j = 0; i < len; i++) {
		while (j > 0 && str[i] != str[j]) j = fail[j - 1];
		if (str[i] == str[j]) fail[i] = ++j;
	}
	return fail;
}


int main() {
	string s;
	cin >> s;
	int Max = 0;
	for (int i = 0; i < s.length(); i++) {
		vector<int> Pi = getFail(s.substr(i, s.length() - i));
		for (int j = 0; j < s.length() - i; j++)
			if (Pi[j] > Max) Max = Pi[j];
	}
	cout << Max;
	return 0;
}