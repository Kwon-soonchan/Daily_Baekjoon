#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int n;
vector<vector<int>> arr;
vector<int> link, start;
int answer = 2e9;

void dfs(int idx) {
	if (idx == n) {
		if (link.empty() || start.empty()) {
			return;
		}

		int score1 = 0;
		int score2 = 0;

		for (int i = 0; i < link.size(); i++) {
			for (int j = i + 1; j < link.size(); j++) {
				score1 += arr[link[i]][link[j]];
			}
		}
		for (int i = 0; i < start.size(); i++) {
			for (int j = i + 1; j < start.size(); j++) {
				score2 += arr[start[i]][start[j]];
			}
		}

		answer = min(answer, abs(score1 - score2));
		return;
	}

	link.push_back(idx);
	dfs(idx + 1);
	link.pop_back();

	start.push_back(idx);
	dfs(idx + 1);
	start.pop_back();
}

int main() {
	cin >> n;
	arr.assign(n, vector<int>(n, 0));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			arr[i][j] += arr[j][i];

		}
	}

	dfs(0);

	cout << answer << endl;

	return 0;
}