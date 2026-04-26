// 10773번 제로
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
	int K;
	cin >> K;

	stack<int> s;

	for (int i = 0; i < K; i++) {
		int n;
		cin >> n;

		if (n != 0) {
			s.push(n);
		}
		else {
			s.pop();
		}

	}

	int sum = 0;

	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	cout << sum;
}