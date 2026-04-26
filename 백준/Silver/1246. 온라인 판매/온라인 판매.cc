#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p_list(m);
    for (int i = 0; i < m; i++) {
        cin >> p_list[i];
    }

    sort(p_list.begin(), p_list.end(), greater<int>());

    int max_profit = 0;
    int best_price = 0;
    int limit = min(n, m);

    for (int i = 0; i < limit; i++) {
        int profit = p_list[i] * (i + 1);
        if (profit > max_profit) {
            max_profit = profit;
            best_price = p_list[i];
        }
    }

    cout << best_price << " " << max_profit << endl;
}