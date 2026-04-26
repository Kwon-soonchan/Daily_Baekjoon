#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<tuple<int, int, int, int>> v;

    for (int i = 0; i < n; i++) {
        int c, g, s, b;
        cin >> c >> g >> s >> b;
        v.push_back({ g, s, b, c });
    }

    sort(v.begin(), v.end(), greater<>());

    int rank = 1;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            if (get<0>(v[i]) != get<0>(v[i-1]) ||
                get<1>(v[i]) != get<1>(v[i-1]) ||
                get<2>(v[i]) != get<2>(v[i-1])) {
                rank = i + 1;
            }
        }
        if (get<3>(v[i]) == k) {
            cout << rank << '\n';
            break;
        }
    }
}