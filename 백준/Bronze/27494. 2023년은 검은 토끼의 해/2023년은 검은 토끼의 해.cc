#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int cnt = 0;


	for (int i = 2023; i <= n; i++) {
		string s = to_string(i);
		string s2 = "2023";
		int index = 0;

		for (char c : s) {
			if(c == s2[index]) {
				index++;
			}
			if (index == 4) {
				break;
			}
		}
		if (index == 4) {
			cnt++;
		}
	}
	cout << cnt << endl;
}