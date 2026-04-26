//#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
using namespace std;
int n;
string op;
vector<vector<int>> m;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int x1 = 60;
int y11 = 60;
int x2 = 60;
int y2 = 60;

int left(int dir) {
    dir--;
    if (dir < 0) dir = 3;
    return dir;
}

int right(int dir) {
    dir++;
    if (dir > 3) dir = 0;
    return dir;
}

void DFS(int x, int y, int dir, int l) {
    if (l == n) {
        for (int i = x1; i <=x2; ++i) {
            for (int j = y11; j <=y2; ++j) {
                if (m[i][j] == 1)
                    cout << ".";
                else
                    cout << "#";
            }
            cout << "\n";
        }
        exit(0);
    }
    if (op[l] == 'R') {
        dir = right(dir);
        DFS(x, y, dir, l + 1);
    }
    else if (op[l] == 'L') {
        dir = left(dir);
        DFS(x, y, dir, l + 1);
    }
    else {
        int xx = x + dx[dir];
        int yy = y + dy[dir];
        if (xx < x1) x1 = xx;
        if (xx > x2) x2 = xx;
        if (yy < y11) y11 = yy;
        if (yy > y2) y2 = yy;
        m[xx][yy] = 1;
        DFS(xx, yy, dir, l + 1);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    cin >> n;
    cin >> op;
    m = vector<vector<int>>(120, vector<int>(120));
    m[60][60] = 1;
    DFS(60, 60, 1, 0);
    return 0;
}