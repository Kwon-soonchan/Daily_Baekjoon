#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b) {
	if (a == 0) {
		return b;
	}
	return gcd(b % a, a);
}

int main() {
	int n;
	cin >> n;

	vector<int> tree;
	int prev;
	cin >> prev;
	
	for (int i = 1; i < n; i++) {
		int x;
		cin >> x;
		tree.push_back(x - prev);
		prev = x;
	}

	int result = 0;
	if (n == 3) {
		int gcd1 = gcd(tree[0], tree[1]);
		for (int i : tree) {
			result += (i / gcd1) - 1;
		}
	}
	else {
		int gcd1 = gcd(tree[0], tree[1]);
		int gcd2 = 0;
		for (int i = 2; i < n; i++) {
			gcd2 = gcd(gcd1, tree[i]);
			gcd1 = gcd2;
		}
		for (int i : tree) {
			result += (i / gcd2) - 1;
		}
	}
	
	cout << result << "\n";
}