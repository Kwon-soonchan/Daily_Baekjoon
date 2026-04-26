// 2309번 일곱 난쟁이
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;

int main() {
	int sum = 0;
	bool check = false;

	for (int i = 0; i < 9; i++) {
		int h;
		cin >> h;
		v.push_back(h);
		sum += h;
	}
	
	sum -= 100;

	for (int i = 0; i < 9; i++) {
		if (check) {
			break;
		}
		for (int j = i + 1; j < 9; j++) {
			if (sum == v[i] + v[j]) {
				v.erase(v.begin() + j);
				v.erase(v.begin() + i);
				check = true;
				break;
			}
		}
	}
	
	sort(v.begin(), v.end());
	
	for (int i : v) {
		cout << i << endl;
	}
}
