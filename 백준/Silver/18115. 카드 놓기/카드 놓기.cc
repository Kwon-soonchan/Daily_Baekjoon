// 18115번 카드 놓기 -> solved.ac 배경 얻기용 문제
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

vector<int> v;
deque<int> dq;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	reverse(v.begin(), v.end());

	int start = 1;

	for (int i = 0; i < n; i++) {
		if (v[i] == 1) {
			dq.push_front(start);
		}
		else if (v[i] == 2) {
			int tmp = dq.front();
			dq.pop_front();
			dq.push_front(start);
			dq.push_front(tmp);
		}
		else if (v[i] == 3) {
			dq.push_back(start);
		}

		start++;
	}

	for (int i : dq) {
		cout << i << ' ';
	}
}