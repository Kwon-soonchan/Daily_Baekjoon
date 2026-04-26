// 1736번 쓰레기 치우기
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int result = 0;
    bool has_trash = true;

    while (has_trash) {
        has_trash = false;
        int last = 0;

        for (int i = 0; i < N; i++) {
            int end = last;
            for (int j = last; j < M; j++) {
                if (board[i][j]) {
                    end = j;
                    has_trash = true;
                }
            }
            for (int j = last; j <= end; j++) {
                board[i][j] = 0;
            }
            last = end;
        }

        if (has_trash) {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}