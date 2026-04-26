#include<iostream>
using namespace std;

int main() {
    long long k;
    cin >> k;

    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    long long left = a * k + b;   // 좌극한, 함숫값
    long long right = c * k + d;  // 우극한

    if (left == right) {
        cout << "Yes " << right << endl;
    } else {
        cout << "No" << endl;
    }
}