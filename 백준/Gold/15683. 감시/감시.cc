// 15683번 감시 -> 결국 구글링....
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[8][8];
vector<pair<int, int>> cctv; // cctv 개수랑 위치 저장
int ans = 987654321;

int dx[4] = { 0, -1, 0, 1 }; // 우, 상, 좌, 하
int dy[4] = { 1, 0, -1, 0 };

void check(int x, int y, int dir) { // cctv 감시범위를 체크하는 함수 -> 0들을 -1로 변경함
    dir %= 4;
    while (1) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) return;
        if (arr[nx][ny] == 6) return;
        if (arr[nx][ny] != 0) continue;
        arr[nx][ny] = -1;
    }
}

// main에서 cctv 개수랑 위치 파악해둔걸 토대로 계속 백트래킹하다가 idx가 cctv 개수랑 같아지면 결과값 반환
void dfs(int idx) { 
    if (idx == cctv.size()) {
        int cnt = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (!arr[i][j]) cnt++;

        ans = min(ans, cnt);
        return;
    }

    int x = cctv[idx].first;
    int y = cctv[idx].second;
    int tmp[9][9];

    for (int dir = 0; dir < 4; dir++) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                tmp[i][j] = arr[i][j];

        if (arr[x][y] == 1)
            check(x, y, dir);
        else if (arr[x][y] == 2) {
            check(x, y, dir);
            check(x, y, dir + 2);
        }
        else if (arr[x][y] == 3) {
            check(x, y, dir);
            check(x, y, dir + 1);
        }
        else if (arr[x][y] == 4) {
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
        }
        else if (arr[x][y] == 5) {
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
            check(x, y, dir + 3);
        }

        dfs(idx + 1);
        // case 종료이므로 초기화
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                arr[i][j] = tmp[i][j];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] != 0 && arr[i][j] != 6)
                cctv.push_back({ i, j });
        }
    }

    dfs(0);
    cout << ans << '\n';

    return 0;
}