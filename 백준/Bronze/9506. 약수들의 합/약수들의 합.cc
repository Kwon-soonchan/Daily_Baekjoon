#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n == -1) {
			break;
		}

		vector<int> factor;
		for (int i = 1; i < n; i++) {
			if (n % i == 0 ) {
				factor.push_back(i);
			}
		}
		int sum = 0;
		for (int i : factor) {
			sum += i;
		}

		if (n == sum) {
			cout << n << " = " << factor[0];
			for (int i = 1; i < factor.size(); i++) {
				if (factor[i] != 0) {
					cout << " + " << factor[i];
				}
			}
			cout << endl;
		}
		else {
			cout << n << " is NOT perfect." << endl;
		}
	}
}