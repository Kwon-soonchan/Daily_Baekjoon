//9252번 LCS2
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

string s1, s2;
int arr[1001][1001];
vector<char> result;

void lcs(int x, int y) {
	if (arr[x][y] == 0) {
		return;
	}
	if (arr[x - 1][y] == arr[x][y]) {
		lcs(x - 1, y);
	}
	else if (arr[x][y - 1] == arr[x][y]) {
		lcs(x, y - 1);
	}
	else {
		result.push_back(s1[x-1]);
		lcs(x - 1, y - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s1 >> s2;

	for (int i = 0; i <= s1.size(); i++) {
		for (int j = 0; j <= s2.size(); j++) {
			if (i == 0) {
				arr[i][j] = 0;
				continue;
			}
			if (j == 0) {
				arr[i][j] = 0;
				continue;
			}

			if (s1[i - 1] == s2[j - 1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else {
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}

	lcs(s1.size(), s2.size());
	
	cout << result.size() << '\n';
	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i];
	}
}