#include<iostream>
#include<vector>
#include<set>
#include<cmath>
using namespace std;

int main() {
	int n, m, b;
	cin >> n >> m >> b;

	vector<vector<int>> height(n, vector<int>(m));
	set<int> s;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int h;
			cin >> h;
			height[i][j] = h;
			s.insert(h);
		}
	}
	int minH = *s.begin();
	int maxH = *s.rbegin();

	int ans = -1;
	int ansH = 0;
	for (int h = minH; h <= maxH; h++) {
		int time = 0;
		int block = b;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (height[i][j] < h) {
					time += (h - height[i][j]);
					block -= (h - height[i][j]);
				}
				else if (height[i][j] > h) {
					time += (height[i][j] - h) * 2;
					block += (height[i][j] - h);
					}
				}
			}
		if (block >= 0) {
			if (ans == -1 || time < ans || (time == ans && h > ansH)) {
				ans = time;
				ansH = h;
			}
		}
	}
	cout << ans << " " << ansH << endl;
}