//#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main(void) {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<int>> ch(n, vector<int>(m, 10000000));
    set<pair<int, int>> S;
    string tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        for (int j = 0; j < m; ++j) {
            if (tmp[j] == 'R')
                arr[i][j] = 0;
            else if(tmp[j] == 'D')
                arr[i][j] = 1;
            else if (tmp[j] == 'L')
                arr[i][j] = 2;
            else if (tmp[j] == 'U')
                arr[i][j] = 3;
        }
    }
    int start = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (ch[i][j] != 10000000) continue;
            else {
                ch[i][j] = start;
                int x = i;
                int y = j;
                S = set<pair<int, int>>();
                S.insert({ x,y });
                while (true) {
                    int xx = x + dx[arr[x][y]];
                    int yy = y + dy[arr[x][y]];
                    if (S.find({ xx,yy })!=S.end()) break;
                    if (ch[xx][yy] <start) {
                        start--;
                        for (pair<int,int> p : S) {
                            ch[p.first][p.second] = start;
                        }
                        break;
                    }
                    if (ch[xx][yy] == 10000000) {
                        //ch[xx][yy] = start;
                        S.insert({ xx,yy });
                        x = xx;
                        y = yy;
                    }
                }
                for (pair<int, int> p : S) {
                    ch[p.first][p.second] = start;
                }
                start++;
            }
        }
    }

    cout << start;
    return 0;
}