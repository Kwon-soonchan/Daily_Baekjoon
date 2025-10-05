#include<iostream>
#include<string>
#include<set>
using namespace std;

int main() {
	int n;
	cin >> n;

	set<string> s;
	for (int i = 0; i < n; i++) {
		string name1, name2;
		cin >> name1 >> name2;

		if (name1 == "ChongChong" || name2 == "ChongChong") {
			s.insert(name1);
			s.insert(name2);
		}
		if (s.find(name1) != s.end()) {
			s.insert(name2);
		}
		if (s.find(name2) != s.end()) {
			s.insert(name1);
		}
	}

	cout << s.size();
}