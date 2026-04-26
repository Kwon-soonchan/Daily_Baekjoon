#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
typedef long long ll;

unordered_map<ll, int> cnt;

void bfs(ll start, ll b) {
    queue<ll> q;
    q.push(start);
    cnt[start] = 0;

    while (!q.empty()) {
        ll cur = q.front();
        q.pop();

        if (cur > b) continue;

        if (cnt.find(cur * 2) == cnt.end() && cur * 2 <= b) {
            cnt[cur * 2] = cnt[cur] + 1;
            q.push(cur * 2);
        }
        if (cnt.find(cur * 10 + 1) == cnt.end() && cur * 10 + 1 <= b) {
            cnt[cur * 10 + 1] = cnt[cur] + 1;
            q.push(cur * 10 + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b;
    cin >> a >> b;

    bfs(a, b);

    if (cnt.find(b) == cnt.end()) {
        cout << -1 << endl;
    } else {
        cout << cnt[b] + 1 << endl;
    }
}