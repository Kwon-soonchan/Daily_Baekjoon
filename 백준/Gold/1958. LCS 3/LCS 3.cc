#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	int a = s1.length();
	int b = s2.length();
	int c = s3.length();

	vector<vector<vector<int>>> v(a + 1, vector<vector<int>>(b + 1, vector<int>(c + 1)));

	// 0 먼저 채우기
	for (int i = 0; i < a + 1; i++) {
		for (int j = 0; j < 1; j++) {
			for (int k = 0; k < 1; k++) {
				v[i][j][k] = 0;
			}
		}
	}
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < b + 1; j++) {
			for (int k = 0; k < 1; k++) {
				v[i][j][k] = 0;
			}
		}
	}
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			for (int k = 0; k < c + 1; k++) {
				v[i][j][k] = 0;
			}
		}
	}

	// LCS
	for (int i = 1; i < a + 1; i++) {
		for (int j = 1; j < b + 1; j++) {
			for (int k = 1; k < c + 1; k++) {
				if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
					v[i][j][k] = v[i - 1][j - 1][k - 1] + 1;
				}
				else {
					v[i][j][k] = max(max(v[i - 1][j][k], v[i][j - 1][k]), v[i][j][k - 1]);
				}
			}
		}
	}

	cout << v[a][b][c] << endl;
}