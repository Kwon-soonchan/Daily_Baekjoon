// 1018번 체스판 다시 칠하기
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

char arr[51][51];
vector<int> cnt;

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i <= (n-8); i++) {
		for (int j = 0; j <= (m-8); j++) {
			for (int color = 0; color <= 1; color++) { // 0: 'W' starts, 1: 'B' starts
				int count = 0;
				for (int k = i; k < (i + 8); k++) {
					for (int l = j; l < (j + 8); l++) {
						if (arr[k][l] != ((k + l + color) % 2 == 0 ? 'W' : 'B')) {
							count++;
						}
					}
				}
				cnt.push_back(count);
			}
		}
	}

	cout << *min_element(cnt.begin(), cnt.end());
}