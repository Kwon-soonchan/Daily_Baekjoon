// 2405번 세 수, 두 M
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long max_diff = 0;

    for (int i = 0; i < n - 2; i++) {
        max_diff = max(max_diff, abs(v[n - 1] + v[i] - v[i + 1] * 2));
    }

    for (int i = 1; i < n - 1; i++) {
        max_diff = max(max_diff, abs(-v[0] + v[i] * 2 - v[i + 1]));
    }

    cout << max_diff << '\n';

    return 0;
}