// 9375번 패션왕 신혜빈
#include<iostream>
#include<string>
#include<unordered_set>
#include<unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		unordered_map<string, int> um;

		for (int i = 0; i < n; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			
			um[s2]++;
		}

		int result = 1;

		for (auto& [s2, cnt] : um) {
			result *= (cnt + 1);
		}

		cout << result - 1 << '\n';
	}
}