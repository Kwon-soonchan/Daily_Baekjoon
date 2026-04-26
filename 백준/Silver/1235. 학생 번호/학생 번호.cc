#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<string> students(n);

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		students[i] = s;
	}

	for (int i = 1; i <= students[0].size(); i++) {
		set<string> s;
		for (int j = 0; j < n; j++) {
			s.insert(students[j].substr(0, i));
		} 
		if (s.size() == n) {
			cout << i << endl;
			break;
		}
	}
}