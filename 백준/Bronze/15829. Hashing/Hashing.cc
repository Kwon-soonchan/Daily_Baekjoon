// 15829번 Hashing
#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	string s;

	cin >> n >> s;

	long long result = 0;
	long long r = 1;
	int MOD = 1234567891;

	for (int i = 0; i < n; i++) {
		int num = s[i] - 'a' + 1;

		result = (result + (num * r) % MOD) % MOD;

		r = (r * 31) % MOD;
	}

	cout << result;
}