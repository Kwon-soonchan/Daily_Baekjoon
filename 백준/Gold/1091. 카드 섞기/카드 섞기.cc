// 1091번 카드 섞기
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n;
int answer = 0;
vector<int> P;
vector<int> S;
vector<int> arr;
set<vector<int>> order;

bool Check() {
	for (int i = 0; i < n; i++) {
		if (P[arr[i]] != i % 3) {
			return false;
		}
	}
	return true;
}

void Shake() {
	if (Check()) {
		cout << answer;
		return;
	}

	vector<int> tmp(n);
	for (int i = 0; i < n; i++) {
		tmp[S[i]] = arr[i];
	}
	arr = tmp;

	if (order.find(arr) != order.end()) {
		cout << -1;
		return;
	}
	order.insert(arr);
	answer++;
	Shake();
}

int main() {
	cin >> n;

	P.resize(n);
	S.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> P[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> S[i];
	}

	arr.resize(n);
	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}

	Shake();

	return 0;
}