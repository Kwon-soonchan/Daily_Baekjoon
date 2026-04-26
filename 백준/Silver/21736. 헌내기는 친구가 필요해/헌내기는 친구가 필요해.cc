#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
bool visited[600][600] = { false, };

void dfs(int x, int y, vector<vector<char>>& v, int n, int m) {
	stack<pair<int, int>> st;
	st.push({ x,y });

	int cnt = 0;

	while (!st.empty()) {
		int cur_x = st.top().first;
		int cur_y = st.top().second;
		st.pop();

		if (visited[cur_x][cur_y]) {
			continue;
		}
		if (v[cur_x][cur_y] == 'P') {
			cnt++;
		}
		visited[cur_x][cur_y] = true;

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) {
				continue;
			}
			if (v[next_x][next_y] == 'I' || v[next_x][next_y] == 'O') {
				st.push({ next_x, next_y });
			}
			else if (v[next_x][next_y] == 'P') {
				st.push({ next_x, next_y });
			}
			else if (v[next_x][next_y] == 'X') {
				continue;
			}
		}
	}
	if (cnt == 0) {
		cout << "TT" << endl;
		return;
	}
	else {
		cout << cnt << endl;
	}
}


int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<char>> v(n, vector<char>(m));
	int me_x = 0;
	int me_y = 0;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'I') {
				me_x = i;
				me_y = j;
			}
			v[i][j] = s[j];
		}
	}

	dfs(me_x, me_y, v, n, m);
}