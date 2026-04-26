#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n;
	cin >> n;
	long long result = n * (n - 1) * (n - 2) / 6;

	cout << result << endl << 3;
}