#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int minPackage = 1001, minSingle = 1001;
	for (int i = 0; i < m; i++) {
		int s, o;
		cin >> s >> o;
		minPackage = min(minPackage, s);
		minSingle = min(minSingle, o);
	}

	int cost1 = ((n + 5) / 6) * minPackage;
	int cost2 = (n / 6) * minPackage + (n % 6) * minSingle;
	int cost3 = n * minSingle;

	int result = min({ cost1, cost2, cost3 });
	cout << result << endl;
}