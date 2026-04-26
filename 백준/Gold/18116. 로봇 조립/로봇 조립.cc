// 18116번 로봇 조립
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1'000'001];
int setSize[1'000'001];

int find(int n) {
	if (parent[n] == n) {
		return n;
	}
	return parent[n] = find(parent[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a < b) {
		parent[b] = a;
		setSize[a] += setSize[b];
		setSize[b] = 0;
	}
	else {
		parent[a] = b;
		setSize[b] += setSize[a];
		setSize[a] = 0;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n;
	cin >> n;

	for (int i = 1; i <= 1'000'001; i++) {
		parent[i] = i;
		setSize[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;

		if (c == 'I') {
			int a, b;
			cin >> a >> b;
			if (find(a) != find(b)) {
				merge(a, b);
			}
		}
		else if (c == 'Q') {
			int a;
			cin >> a;
			cout << setSize[find(a)] << '\n';
		}
	}
}