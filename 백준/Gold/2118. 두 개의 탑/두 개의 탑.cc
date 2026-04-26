#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    vector<int> pre(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++) {
        pre[i] = pre[i - 1] + v[(i - 1) % n];
    }

    int min_diff = sum;
    int answer = sum;

    int left = 0, right = 1;
    while (left < n) {
        while (right - left < n && right <= 2 * n) {
            int tower = pre[right] - pre[left];
            int other = sum - tower;
            int diff = abs(tower - other);

            if (diff < min_diff) {
                min_diff = diff;
                answer = min(tower, other);
            }
            else if (diff == min_diff) {
                answer = min(answer, min(tower, other));
            }

            if (tower < sum / 2.0) {
                right++;
            }
            else {
                break;
            }
        }
        left++;
        if (right < left + 1) right = left + 1;
    }

    cout << answer << '\n';
}
