// 2502번 떡 먹는 호랑이
#include <iostream>
using namespace std;

pair<int, int> findAB(int D, int K) {
    int fib[31] = { 0, 1 };
    for (int i = 2; i <= D; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (int A = 1; A <= K; A++) {
        if ((K - A * fib[D - 2]) % fib[D - 1] == 0) {
            int B = (K - A * fib[D - 2]) / fib[D - 1];
            if (B >= A) return { A, B };
        }
    }
    return { -1, -1 };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int D, K;
    cin >> D >> K;

    pair<int, int> result = findAB(D, K);
    int A = result.first;
    int B = result.second;

    cout << A << '\n' << B << '\n';

}