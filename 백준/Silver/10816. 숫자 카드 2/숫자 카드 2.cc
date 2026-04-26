// 10816번 숫자 카드 2  --> unordered_map 사용
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	unordered_map<int, int> um;

	for (int i = 0; i < n; i++) {
		int N;
		cin >> N;
		um[N]++;
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int M;
		cin >> M;

		cout << um[M] << ' ';
	}
}