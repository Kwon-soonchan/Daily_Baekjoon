// 10989번 수 정렬하기 3 --> 숫자의 범위가 적을때 사용하는 계수정렬
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> count(10001, 0);

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        count[num]++;
    }

    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < count[i]; j++) {
            cout << i << '\n';
        }
    }

    return 0;
}