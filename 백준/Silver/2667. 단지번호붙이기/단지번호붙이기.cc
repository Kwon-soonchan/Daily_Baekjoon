#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> map;
vector<pair<int, int>> stack;
bool visited[25][25] = { false, };
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin >> n;

    map.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    int cnt = 0;
    vector<int> sizes;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                cnt++;
                int size = 0;
                stack.push_back({ i, j });
                visited[i][j] = true;

                while (!stack.empty()) {
                    int x = stack.back().first;
                    int y = stack.back().second;
                    stack.pop_back();
                    size++;
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == 1 && !visited[nx][ny]) {
                            visited[nx][ny] = true;
                            stack.push_back({ nx, ny });
                        }
                    }
                }
                sizes.push_back(size); // 단지 크기 저장 (여기서만!)
            }
        }
    }
    cout << cnt << '\n';
    sort(sizes.begin(), sizes.end());
    for (int s : sizes) cout << s << '\n';
}