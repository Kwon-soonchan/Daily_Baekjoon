// 13711번 LCS 4 -> gpt 제공 코드
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> A(n);
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        pos[a] = i;
    }

    vector<int> lis;
    for (int i = 0; i < n; i++) {
        int index = pos[A[i]];
        auto it = lower_bound(lis.begin(), lis.end(), index);
        if (it == lis.end()) {
            lis.push_back(index);
        }
        else {
            *it = index;
        }
    }

    cout << lis.size() << '\n';
    return 0;
}
