#include<iostream>
#include<queue>
#include<cmath> // double, float형 abs
#include<cstdlib> // int형 abs
using namespace std;

struct compare {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) {
			return a > b; // 절댓값이 같으면 작은 값 우선
		}
		return abs(a) > abs(b); // 절댓값이 다르면 작은 값 우선
	}
};;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, compare> pq;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x != 0) {
			pq.push(x);
		}	
		else {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}
}