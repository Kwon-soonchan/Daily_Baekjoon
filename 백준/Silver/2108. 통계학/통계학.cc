#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    double sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    sort(v.begin(), v.end());

    // 산술평균
    int avg = round(sum / n);
    if (avg == -0) avg = 0;
    cout << avg << '\n';

    // 중앙값
    cout << v[n / 2] << '\n';

    // 최빈값
    int mode_max = 0; // 최빈값의 빈도수
    vector<int> modes; // 최빈값 후보들

    int cur = v[0], cnt = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] == cur) {
            cnt++;
        } else {
            if (cnt > mode_max) {
                mode_max = cnt;
                modes.clear();
                modes.push_back(cur);
            } else if (cnt == mode_max) {
                modes.push_back(cur);
            }
            cur = v[i];
            cnt = 1;
        }
    }
    // 마지막 값 처리
    if (cnt > mode_max) {
        mode_max = cnt;
        modes.clear();
        modes.push_back(cur);
    } else if (cnt == mode_max) {
        modes.push_back(cur);
    }

    if (modes.size() == 1) {
        cout << modes[0] << '\n';
    } else {
        sort(modes.begin(), modes.end());
        cout << modes[1] << '\n'; // 두 번째로 작은 값
    }

    // 범위
    cout << v.back() - v.front() << '\n';
}