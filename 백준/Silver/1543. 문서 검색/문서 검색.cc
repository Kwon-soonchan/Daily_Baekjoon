#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	int cnt = 0;
	string s3 = "0";
	while (true) {
		auto a = s1.find(s2);
		if (a != string::npos) {
			s1.replace(a, s2.length(), s3);
			cnt++;
		}
		else {
			cout << cnt << endl;
			return 0;
		}
	}
}