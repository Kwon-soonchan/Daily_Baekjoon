// 23048번 자연수 색칠하기
#include <vector>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> num(n + 1);
    for (int i = 1; i <= n; i++) {
        num[i] = i;
    }

    vector<int> sosus;
    for (int i = 2; i <= n; i++) {
        if (num[i] == i) {
            sosus.push_back(i);
            if (i <= n / i) {
                for (int j = i * i; j <= n; j += i) {
                    if (num[j] == j) {
                        num[j] = i;
                    }
                }
            }
            
        }
    }

    int cnt = 1;
    vector<int> result(n + 1, 0);
    result[1] = 1;

    for (int sosu : sosus) {
        cnt++;
        for (int i = sosu; i <= n; i += sosu) {
            if (result[i] == 0) {
                result[i] = cnt;
            }
        }
    }

    cout << cnt << '\n';
    for (int i = 1; i <= n; i++) {
        cout << result[i] << ' ';
    }
}