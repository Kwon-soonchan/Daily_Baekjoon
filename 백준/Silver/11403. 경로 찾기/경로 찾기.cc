#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> graph(101, vector<int>(101, 0));

void floyd() {
	int n = graph.size() - 1; // Adjust for 1-based indexing
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (graph[i][k] == 1 && graph[k][j] == 1) {
					graph[i][j] = 1;
				}
			}
		}
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;

			if (x == 0) {
				continue;
			}
			else if (x == 1) {
				graph[i + 1][j + 1] = 1;
			}
		}
	}

	floyd();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << graph[i + 1][j + 1] << " ";
		}
		cout << "\n";
	}
}