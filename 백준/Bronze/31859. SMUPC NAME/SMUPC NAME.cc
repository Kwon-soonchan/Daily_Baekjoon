// 31859번 SMUPC NAME
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int n, cnt = 4;
	string s1,s2;

	cin >> n >> s1;

	//1단계
	for (char c : s1) {
		if (find(s2.begin(), s2.end(), c) == s2.end()) {
			s2 += c;
		}
		else {
			cnt++;
		}
	}

	//2단계
	s2 += to_string(cnt);

	//3단계 + 4단계
	n += 1906;

	reverse(s2.begin(), s2.end());

	for (int i = 0; i < 4; i++) {
		s2 += to_string(n % 10);
		n = n / 10;
	}

	//5단계
	cout << "smupc_" << s2;
}