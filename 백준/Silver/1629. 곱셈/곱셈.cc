#include <iostream>
typedef long long ll;
using namespace std;

int c;

ll calc(ll a, ll b) {
	if (b == 0) {
		return 1;
	}

	if (b == 1) {
		return a;
	}

	ll result = (calc(a, b / 2) * calc(a, b / 2)) % c;

	if (b % 2 == 1) {
		result = (result * a)%c;
	}

	return (result)%c;
}

int main() {
	int a, b;
	cin >> a >> b >> c;

	cout << calc(a, b) % c;
}
