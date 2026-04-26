// 11866번 요세푸스 문제 0
#include<iostream>
#include<vector>
using namespace std;

vector<int> v;
vector<int> yo;
int flag = 0;

int yosepus(int n, int k) {
	if (n == 0) {
		return 0;
	}
	else {
		flag = (flag + k - 1) % n;
		yo.push_back(v[flag]);
		v.erase(v.begin() + flag);
	}

	return yosepus(n - 1, k);
}

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}

	yosepus(n, k);

	cout << "<";
	for (int i = 0; i < yo.size(); i++) {
		cout << yo[i];
		
		if (i != yo.size() - 1) {
			cout << ", ";
		}
	}
	cout << ">";
}