// 1717번 집합의 표현
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1'000'000];


int find(int n) {
	if (parent[n] == n) {
		return n;
	}
	else {
		parent[n] = find(parent[n]);
		return parent[n];
	}
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) {
		return;
	}
	parent[b] = a;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int union_check, a, b;
		cin >> union_check >> a >> b;
		if (union_check == 0) {
			merge(a, b);
		}
		else if (union_check == 1) {
			if (find(a) == find(b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
}