#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);

		vector<string> v;
		stringstream ss(s);

		string word;
		while (ss >> word) {
			v.push_back(word);
		}
		for (int j = 0; j < v.size(); j++) {
			reverse(v[j].begin(), v[j].end());
			cout << v[j] << " ";
		}
		cout << endl;
	}
}