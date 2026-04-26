#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	map<int,string> mp;

	string name;
	int d, m, y;

	int max = 0, min = 0;

	for (int i = 0; i < n; i++) {
		cin >> name >> d >> m >> y;
		int key = y * 10000 + m * 100 + d;
		mp.insert(make_pair(key, name));
	}

	cout << mp.rbegin()->second << "\n";
	cout << mp.begin()->second << "\n";
}