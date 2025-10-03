#include<iostream>
#include<cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int cnt = static_cast<int>(sqrt(n));
	cout << cnt;
}