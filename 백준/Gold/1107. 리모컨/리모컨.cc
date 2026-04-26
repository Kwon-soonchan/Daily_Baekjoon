#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
	int goal, n;
	cin >> goal >> n;
	vector<int> broken(n);

	for (int i = 0; i < n; i++) {
		cin >> broken[i];
	}
	int minPress = abs(goal - 100);
	for (int i = 0; i < 999999; i++) {
		string s = to_string(i);
		bool isBroken = false;

		for (char c : s) {
			if (find(broken.begin(), broken.end(), c - '0') != broken.end()) {
				isBroken = true;
				break;
			}
		}
		if (!isBroken) {
			int preesCnt = abs(goal - i) + s.length();
			if (preesCnt < minPress) {
				minPress = preesCnt;
			}
		}
	}
	cout << minPress << endl;
}