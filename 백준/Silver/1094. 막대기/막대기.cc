#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x;
	cin >> x;

	vector<int> stick;
	stick.push_back(64);

	while (true) {
		int sum = 0;
		for (int i = 0; i < stick.size(); i++) {
			sum += stick[i];
		}
		if (sum == x) {
			cout << stick.size() << endl;
			break;
		}
		int half = stick.back() / 2;
		stick.back() = half;
		stick.push_back(half);

		sum = 0;
		for (int i = 0; i < stick.size(); i++) {
			sum += stick[i];
		}
		if (sum - stick.back() >= x) {
			stick.pop_back();
		}
	}
}