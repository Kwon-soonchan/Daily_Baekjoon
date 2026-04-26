#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(5, 0));
    vector<int> cnt(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = 0; k < 5; k++) {
                if (v[i][k] == v[j][k]) {
                    cnt[i]++;
                    break;
                }
            }
        }
    }

    int max_cnt = *max_element(cnt.begin(), cnt.end());

    for (int i = 0; i < n; i++) {
        if (cnt[i] == max_cnt) {
            cout << i + 1 << endl;
            break;
        }
    }
}