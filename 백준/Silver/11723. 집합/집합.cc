// 11723번 집합 (bool 배열)
#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m;
	cin >> m;

	bool check[21] = { false };  // 1~20까지 사용

	while (m--) {
		string s;
		int n;
		cin >> s;

		if (s == "add") {
			cin >> n;
			check[n] = true;
		}
		else if (s == "remove") {
			cin >> n;
			check[n] = false;
		}
		else if (s == "check") {
			cin >> n;
			cout << check[n] << '\n';
		}
		else if (s == "toggle") {
			cin >> n;
			check[n] = !check[n];
		}
		else if (s == "all") {
			for (int i = 1; i <= 20; i++) {
				check[i] = true;
			}
		}
		else if (s == "empty") {
			for (int i = 1; i <= 20; i++) {
				check[i] = false;
			}
		}
	}
}
