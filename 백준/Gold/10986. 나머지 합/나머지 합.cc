// 10986번 나머지 합
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> count(M, 0);
    long long sum = 0;
    long long result = 0;
    count[0] = 1;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        sum = (sum + num) % M;
        result += count[sum];
        count[sum]++;
    }

    cout << result << endl;
    return 0;
}