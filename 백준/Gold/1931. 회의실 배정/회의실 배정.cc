#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int,int>> meeting(n);
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		meeting[i] = { e, s }; // end time first for sorting
	}
	sort(meeting.begin(), meeting.end());

	int cnt = 1;
	int endTime = meeting[0].first;

	for (int i = 1; i < n; i++) {
		if (meeting[i].second >= endTime) {
			cnt++;
			endTime = meeting[i].first;
		}
	}
	cout << cnt << endl;
}