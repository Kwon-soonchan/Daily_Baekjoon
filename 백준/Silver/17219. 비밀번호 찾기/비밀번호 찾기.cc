// 17219번 비밀번호 찾기
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	string site, pw;
	unordered_map<string, string> mp;

	for (int i = 0; i < n; i++) {
		cin >> site >> pw;
		mp.insert({ site,pw });
	}

	for (int i = 0; i < m; i++) {
		cin >> site;
		cout << mp[site] << '\n';
	}
}