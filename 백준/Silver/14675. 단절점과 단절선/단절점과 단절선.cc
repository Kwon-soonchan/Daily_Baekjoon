#include <iostream>
#include <vector>
using namespace std;


vector <int> v[100'000];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n, a, b, q, t, k;
	cin >> n;

	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);

	}

	cin >> q;

	for (int i = 0; i < q; i++) {
		cin >> t >> k;
		if (t == 2) {
			cout << "yes\n";
		}
		else if (t == 1) {
			if (v[k].size() >= 2) {
				cout << "yes\n";
			}
			else {
				cout << "no\n";
			}

		}
	}
}