#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int n, m;
int arr[101][101];

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == INF) cout << "0 ";
            else cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        fill(arr[i], arr[i] + (n+1), INF);
        arr[i][i] = 0;
    }

    for (int x = 0; x < m; x++) {
        int a, b, cost;
        cin >> a >> b >> cost;

        if (arr[a][b] > cost)
            arr[a][b] = cost;
    }
    floyd();

    return 0;
}