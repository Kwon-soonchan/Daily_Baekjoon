// 1620번 나는야 포켓몬 마스터 이다솜
#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	vector<string> v(n);
	unordered_map<string, int> um;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		um[v[i]] = i;
	}

	string s;

	for (int i = 0; i < m; i++) {
		cin >> s;
		if (isdigit(s[0])) {
			cout << v[stoi(s) - 1] << '\n';
		}
		else {
			cout << um[s] + 1 << '\n';
		}
	}
}