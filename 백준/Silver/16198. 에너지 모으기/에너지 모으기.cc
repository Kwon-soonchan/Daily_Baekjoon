// 16198번 에너지 모으기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxEnergy = 0;

void bt(vector<int>& w, int energy) {
    int n = w.size();

    if (n == 2) {
        maxEnergy = max(maxEnergy, energy);
        return;
    }

    for (int i = 1; i < n - 1; i++) {
        int curEnergy = w[i - 1] * w[i + 1];
        int removed = w[i];

        w.erase(w.begin() + i);
        bt(w, energy + curEnergy);
        w.insert(w.begin() + i, removed);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    bt(w, 0);

    cout << maxEnergy;
}