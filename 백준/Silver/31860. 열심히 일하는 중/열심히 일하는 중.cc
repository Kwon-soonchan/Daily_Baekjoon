// 31860번 열심히 일하는 중
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

priority_queue<int> pq;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m, k, d, cnt = 0;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> d;
        pq.push(d);
    }

    vector<int> satisfactions;

    while (!pq.empty()) {
        int top = pq.top();
        pq.pop();
        if (top > k) {
            cnt++;
            int satisfaction = satisfactions.empty() ? top : satisfactions.back() / 2 + top;
            satisfactions.push_back(satisfaction);
            if (top > m) {
                pq.push(top - m);
            }
        }
    }

    cout << cnt << '\n';

    for (int satisfaction : satisfactions) {
        cout << satisfaction << '\n';
    }
}