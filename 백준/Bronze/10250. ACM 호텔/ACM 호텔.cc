// 10250번 ACM 호텔
#include<iostream>
#include<string>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int h, w, n;
		cin >> h >> w >> n;

		int Y = (n - 1) % h + 1;
		int X = (n - 1) / h + 1;

		cout << Y * 100 + X << '\n';
	}
}