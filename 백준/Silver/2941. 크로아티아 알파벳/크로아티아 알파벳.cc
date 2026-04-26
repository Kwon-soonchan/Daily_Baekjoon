// 2941번 크로아티아 알파벳
#include<iostream>
#include<string>
using namespace std;

string cro[] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < 8; i++) {
		int pos = 0;

		while ((pos = s.find(cro[i], pos)) != string::npos) {
			s.replace(pos, cro[i].length(), "*");
			pos++;
		}
	}

	cout << s.length();
}