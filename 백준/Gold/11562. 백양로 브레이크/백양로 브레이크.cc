#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int n, m;
int arr[251][251];

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		fill(arr[i], arr[i] + n + 1, INF);
		arr[i][i] = 0;
	}

	for (int x = 0; x < m; x++) {
		int a, b, cost;
		cin >> a >> b >> cost;

		arr[a][b] = 0;
		if (cost == 1)
			arr[b][a] = 0;
		else
			arr[b][a] = 1;
	}

	floyd();

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (arr[i][j] == INF)
				arr[i][j] = 0;
		}
	}

	int qNums, start, end;
	cin >> qNums;

	for (int i = 0; i < qNums; i++) {
		cin >> start >> end;
		cout << arr[start][end] << ' ';
	}

	return 0;
}
