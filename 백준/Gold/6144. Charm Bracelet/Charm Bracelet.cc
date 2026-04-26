// 6144번 Charm Bracelet
#include<iostream>
#include<algorithm>
using namespace std;

int dp[12880];
int W[3402];
int V[3402];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> W[i] >> V[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= W[i]; j--) {
            dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
        }
    }
    cout << dp[m];
}