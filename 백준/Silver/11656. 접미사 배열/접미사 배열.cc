#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<string> v;
	
	for (int i = 0; i < s.size(); i++) {
		string word = "";
		for (int j = i; j < s.size(); j++) {
			word += s[j];
		}
		v.push_back(word);
	}
	sort(v.begin(), v.end());
	for (string str : v) {
		cout << str << endl;
	}
}