// 14889번 스타트와 링크
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k;
int min_stat = 2e9;
vector<int> start;
vector<int> link;
vector<int> st[20];
vector<int> num;
vector<int> index;

int calc(vector<int> team) {
	int result = 0;

	for (int i = 0; i < team.size(); i++) {
		for (int j = i+1; j < team.size(); j++) {
			result += st[team[i]][team[j]] + st[team[j]][team[i]];
		}
	}

	return result;
}

int main() {
	cin >> n;
	k = n / 2;

	for (int i = 0; i < n; i++) {
		num.push_back(i);
		for (int j = 0; j < n; j++) {
			int s;
			cin >> s;
			st[i].push_back(s);
		}
	}
	for (int i = 0; i < k; i++) {
		index.push_back(1);
	}
	for (int i = 0; i < num.size() - k; i++) {
		index.push_back(0);
	}

	sort(index.begin(), index.end());

	do
	{
		start.clear();
		link.clear();

		for (int i = 0; i < index.size(); i++) {
			if (index[i] == 0) {
				start.push_back(num[i]);
			} 
			else {
				link.push_back(num[i]);
			}
		}
		int diff = abs(calc(start) - calc(link));
		min_stat = min(min_stat, diff);
	} while (next_permutation(index.begin(), index.end()));


	cout << min_stat;
}
