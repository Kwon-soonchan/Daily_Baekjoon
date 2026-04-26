// 13277번 큰 수 곱셈
#include <bits/stdc++.h>
using namespace std;

typedef complex<double> base;
void fft(vector<base>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * M_PI / len * (invert ? -1 : 1);
        base wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            base w(1);
            for (int j = 0; j < len / 2; j++) {
                base u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) for (base& x : a) x /= n;
}

vector<int> multiply(vector<int>& a, vector<int>& b) {
    vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa, false); fft(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);
    vector<int> result(n);
    for (int i = 0; i < n; i++) result[i] = round(fa[i].real());
    int carry = 0;
    for (int i = 0; i < n; i++) {
        result[i] += carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }
    while (!result.empty() && !result.back()) result.pop_back();
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;
    vector<int> a(s1.rbegin(), s1.rend()), b(s2.rbegin(), s2.rend());
    for (int& x : a) x -= '0';
    for (int& x : b) x -= '0';

    vector<int> result = multiply(a, b);
    if (result.empty()) cout << "0";
    else for (int i = result.size() - 1; i >= 0; i--) cout << result[i];
    cout << "\n";

    return 0;
}