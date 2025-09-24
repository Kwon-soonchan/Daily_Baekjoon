#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	set<int> s1;
	set<int> s2;
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < a; i++) {
		int n;
		cin >> n;
		s1.insert(n);
	}
	for (int i = 0; i < b; i++) {
		int n;
		cin >> n;
		s2.insert(n);
	}

	for (auto iter = s1.begin(); iter != s1.end(); iter++) {
		if (s2.find(*iter) != s2.end()) {
			continue;
		}
		else {
			v1.push_back(*iter);
		}
	}
	for (auto iter = s2.begin(); iter != s2.end(); iter++) {
		if (s1.find(*iter) != s1.end()) {
			continue;
		}
		else {
			v2.push_back(*iter);
		}
	}

	cout << v1.size() + v2.size() << "\n";
}