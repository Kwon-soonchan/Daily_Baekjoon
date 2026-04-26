// 17281번 야구
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[51][10];
int order[9];
bool selec[10];
int maxsum = 0;

void sumscore() {
    int score = 0;
    int start_player = 0;
    bool next;
    bool base[4];

    for (int e = 0; e < n; e++) {
        int outcount = 0;
        next = false;
        memset(base, false, sizeof(base));

        while (1) {
            for (int i = start_player; i < 9; i++) {

                int player = arr[e][order[i]];

                if (player == 0) {
                    outcount++;
                }
                else if (player == 1) {
                    for (int x = 3; x > 0; x--) {
                        if (base[x] == true) {
                            if (x == 3) {
                                base[x] = false;
                                score++;
                            }
                            else {
                                base[x + 1] = true;
                                base[x] = false;
                            }
                        }
                    }
                    base[1] = true;
                }
                else if (player == 2) {
                    for (int x = 3; x > 0; x--) {
                        if (base[x] == true) {
                            if (x == 3 || x == 2) {
                                score++;
                                base[x] = false;
                            }
                            else {
                                base[x + 2] = true;
                                base[x] = false;
                            }
                        }
                    }
                    base[2] = true;
                }
                else if (player == 3) {
                    for (int x = 3; x > 0; x--) {
                        if (base[x] == true) {
                            score++;
                            base[x] = false;
                        }
                    }
                    base[3] = true;
                }
                else
                {
                    for (int x = 3; x > 0; x--) {
                        if (base[x] == true) {
                            score++;
                            base[x] = false;
                        }
                    }
                    score++;
                }
                if (outcount == 3) {
                    start_player = i + 1;
                    if (start_player == 9) start_player = 0;
                    next = true;
                    break;

                }
            }
            if (next == true) break;
            start_player = 0;
        }
    }

    maxsum = max(maxsum, score);
}

void dfs(int cnt) {
    if (cnt == 9) {
        sumscore();
        return;
    }
    for (int i = 0; i < 9; i++) {
        if (selec[i] == true) continue;
        selec[i] = true;
        order[i] = cnt;

        dfs(cnt + 1);

        selec[i] = false;
    }
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < 9; j++)
            cin >> arr[i][j];
    }
        
    selec[3] = true;
    order[3] = 0;
    dfs(1);

    cout << maxsum;

    return 0;

}