#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int n, m;
const int INF = 987654321;
int graph[101][101];

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				graph[i][j] = 0;
			}
			else {
				graph[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	floyd();

	int min_sum = INF;
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += graph[i][j];
		}
		if (sum < min_sum) {
			min_sum = sum;
			answer = i;
		}
	}
	cout << answer << endl;
}