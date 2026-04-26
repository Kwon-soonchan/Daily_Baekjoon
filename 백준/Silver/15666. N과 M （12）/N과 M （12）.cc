#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v;
vector<int> num;

void dfs(int depth, int start) {
    if (m == depth) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int prev = -1; // 이전에 선택한 값 저장 (입력값이 음수일 수 있으니 -1로 초기화)
    for (int i = start; i < n; i++) {
        if (prev != num[i]) { // 같은 depth에서 같은 값이면 건너뜀
            v.push_back(num[i]);
            dfs(depth + 1, i); // i를 넘기면 중복 선택 가능
            v.pop_back();
            prev = num[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }
    sort(num.begin(), num.end());

    dfs(0, 0);
}