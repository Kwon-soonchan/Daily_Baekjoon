// 16975번 수열과 쿼리 21
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int MAX = 1000001;  // 최대 사이즈 지정

vector<ll> tree(MAX, 0);

// 펜윅 트리 업데이트 함수
void update(int idx, ll diff) {
    while (idx < MAX) {
        tree[idx] += diff;
        idx += (idx & -idx);
    }
}

// 1부터 idx까지의 구간 합 계산 함수
ll sum(int idx) {
    ll result = 0;
    while (idx > 0) {
        result += tree[idx];
        idx -= (idx & -idx);
    }
    return result;
}

// 구간 업데이트 함수
void range_update(int l, int r, ll val) {
    update(l, val);
    update(r + 1, -val);
}

// 점 쿼리 함수
ll point_query(int idx) {
    return sum(idx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        range_update(i, i, a);
    }

    int m;
    cin >> m;

    for (int i = 1; i <= m; i++) {
        int q;
        cin >> q;

        if (q == 1) {
            int i, j, k;
            cin >> i >> j >> k;
            range_update(i, j, k);
        }
        else {
            int x;
            cin >> x;
            cout << point_query(x) << '\n';
        }
    }
    return 0;
}