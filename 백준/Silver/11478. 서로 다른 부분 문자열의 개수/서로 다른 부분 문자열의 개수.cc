#include<iostream>
#include<string>
#include<set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;

	set<string> s;

	for (int i = 0; i < str.length(); i++) {
		for (int j = i; j < str.length(); j++) {
			string str1 = "";
			for (int k = i; k <= j; k++) {
				str1 += str[k];
			}
			s.insert(str1);
		}
	}

	int cnt = s.size();
	cout << cnt << "\n";
}