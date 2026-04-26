// 29160번 나의 FIFA 팀 가치는?
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

priority_queue<int> player[11];
int sunbal[11] = { 0 };

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int p, w;
        cin >> p >> w;
        player[p - 1].push(w);
    }

    for (int j = 0; j < k; j++) {
        for (int i = 0; i < 11; i++) {
            if (!player[i].empty()) {
                sunbal[i] = player[i].top();
                player[i].pop();
            }
            else {
                sunbal[i] = 0;
            }
        }

        for (int i = 0; i < 11; i++) {
            sunbal[i] = max(sunbal[i] - 1, 0);
            if (sunbal[i] > 0) {
                player[i].push(sunbal[i]);
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 11; i++) {
        if (!player[i].empty()) {
            sum += player[i].top();
        }
    }

    cout << sum;

    return 0;
}