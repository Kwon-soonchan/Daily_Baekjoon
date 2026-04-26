// 7568번 덩치
#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> v;

int main() {
	int n;
	cin >> n;
	
	vector<int> grade(n, 1);

	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			else {
				if (v[i].first < v[j].first && v[i].second < v[j].second) {
					grade[i]++;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << grade[i] << ' ';
	}
}