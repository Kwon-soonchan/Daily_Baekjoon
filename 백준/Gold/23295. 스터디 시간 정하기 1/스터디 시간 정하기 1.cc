//23295번 스터디 시간 정하기1
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
ll arr[200'001];
ll cnt[200'001];
ll sum[200'001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, t;
    cin >> n >> t;

    ll max_time = 0;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            ll a, b;
            cin >> a >> b;
            arr[a] += 1;
            arr[b] -= 1;
            max_time = max(max_time, b);
        }
    }
    
    cnt[0] = arr[0];
    sum[0] = arr[0];
    
    for (int i = 1; i <= max_time; i++) {
        cnt[i] = cnt[i - 1] + arr[i];
        sum[i] = sum[i - 1] + cnt[i];
    }

    ll max_cnt = 0, start_point = 0;

    for (ll point = 0; point <= max_time; point++) {
        ll calc;
        if (point == 0) {
            calc = sum[point + t] - cnt[point + t];
        }
        else {
            calc = sum[point + t] - sum[point - 1] - cnt[point + t];
        }
        if (calc > max_cnt) {
            max_cnt = calc;
            start_point = point;
        }
    }
    cout << start_point << " " << start_point + t;
}