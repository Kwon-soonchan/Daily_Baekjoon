// 1342번 행운의 문자열
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int cnt = 0;
	int real_cnt = 0;
	string s;
	cin >> s;

	vector<char> v;

	for (char c : s) {
		v.push_back(c);
	}

	sort(v.begin(), v.end());

	do
	{
		for (int i = 0; i < v.size()-1; i++) {
			if (v[i] != v[i + 1]) {
				cnt++;
			}
		}
		if (cnt == v.size()-1) {
			real_cnt++;
		}
		cnt = 0;
	} while (next_permutation(v.begin(), v.end()));

	cout << real_cnt;

	return 0;
}