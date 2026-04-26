// 1484번 다이어트
#include<iostream>
#include<vector>
using namespace std;

vector<int> v;
vector<int> list;

int main() {
	int g;
	cin >> g;

	for (int i = 1; i <= 100'000; i++) {
		v.push_back(i);
	}

	int st = 0, en = 0;

	while (en < 100'000) {
		int result = (v[en] * v[en]) - (v[st] * v[st]);
		if (result < g) {
			en++;
		}
		else if(result > g){
			st++;
		}
		else{
			list.push_back(v[en]);
			en++;
		}
	}
	if (list.size() == 0) {
		cout << -1;
	}
	else {
		for (int i : list) {
			cout << i << '\n';
		}
	}

}

