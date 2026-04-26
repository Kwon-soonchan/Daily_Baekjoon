// 25840번 Sharing Birthday
#include<iostream>
#include<string>
#include<set>
using namespace std;

int main() {
	int n, count = 0;
	cin >> n;
	
	string s1;
	set<string> s;

	for (int i = 0; i < n; i++) {
		cin >> s1;
		s.insert(s1);
	}
	cout << s.size();
}
