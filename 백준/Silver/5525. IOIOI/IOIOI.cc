#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;

	string result = "I";
	for (int i = 0; i < n; i++) {
		result += "OI";
	}

	int cnt = 0;
	int i = 0;

	while (i < m - 1) {
		int pattern = 0;

		if (s[i] == 'I') {
			while (i + 2 < m && s[i + 1] == 'O' && s[i + 2] == 'I') {
				pattern++;
				i += 2;
				if (pattern == n) {
					cnt++;
					pattern--;  // 다음 패턴 중첩 위해 줄임
				}
			}
		}
		i++;
	}
	cout << cnt << endl;
}