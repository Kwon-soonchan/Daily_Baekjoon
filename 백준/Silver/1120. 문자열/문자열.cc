#include<iostream>
#include<string>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	int min_cnt = a.length();

	for (int i = 0; i <= b.length() - a.length(); i++) {
		int cnt = 0;
		for (int j = 0; j < a.length(); j++) {
			if (a[j] != b[i + j]) {
				cnt++;
			}
		}
		if (cnt < min_cnt) {
			min_cnt = cnt;
		}
	}

	cout << min_cnt << endl;
}