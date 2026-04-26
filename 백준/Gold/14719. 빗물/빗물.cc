// 14719번 빗물
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<int> block(w);
    for (int i = 0; i < w; i++) {
        cin >> block[i];
    }

    int water = 0;
    int L = 0;
    int R = w - 1;
    int max_L = 0;
    int max_R = 0;

    while (L <= R) {
        if (block[L] <= block[R]) {
            if (block[L] > max_L) {
                max_L = block[L];
            }
            else {
                water += max_L - block[L];
            }
            L++;
        }
        else {
            if (block[R] > max_R) {
                max_R = block[R];
            }
            else {
                water += max_R - block[R];
            }
            R--;
        }
    }

    cout << water;
}