#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	string result = "";

	for (int i = 1; i < s.size() - 1; ++i) {
		for (int j = i + 1; j < s.size(); ++j) {
			string a = s.substr(0, i);
			string b = s.substr(i, j - i);
			string c = s.substr(j, s.size() - j);

			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
			reverse(c.begin(), c.end());

			string temp = a + b + c;

			if (result.empty() || temp < result) {
				result = temp;
			}
		}
	}
	cout << result << endl;
}