// 13144번 list of unique numbers
#include<iostream>
#include<algorithm>
using namespace std;

int list[100'001];
int visited[100'001];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >>	list[i];
	}

	fill_n(visited, 100'001, -1);
	
	long long cnt = 0;
	int st = 0;

	for (int en = 0; en < n; en++) {
		if (visited[list[en]] >= st) {
			st = visited[list[en]] + 1;
		}

		cnt += (en - st + 1);

		visited[list[en]] = en;

	}

	cout << cnt << '\n';
}