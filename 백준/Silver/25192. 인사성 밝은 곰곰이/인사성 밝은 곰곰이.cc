#include<iostream>
#include<set>
#include<string>
using namespace std;

int main() {
	int n;
	cin >> n;

	int cnt = 0;
	set<string> s;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		
		if (str == "ENTER") {
			s.clear();
			continue;
		}
		if (s.find(str) == s.end()) {
			s.insert(str);
			cnt++;
		}
	}
	cout << cnt << "\n";
}