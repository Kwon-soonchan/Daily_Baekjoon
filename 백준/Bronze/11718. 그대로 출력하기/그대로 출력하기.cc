// 11718번 그대로 출력하기
#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;

	while (true) {
		getline(cin, s);
		
		if (s == "") {
			break;
		}
		
		cout << s << '\n';
	}
}