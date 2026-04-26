// 12101번 1,2,3 더하기 2
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int cnt = 0;
vector<string> v;

void bt(int n, vector<int>& cur) {
	if (n == 0) {
		string result;

		for (int i = 0; i < cur.size(); i++) {
			if (i > 0) {
				result += "+";
			}
			result += to_string(cur[i]);
		}
		v.push_back(result);
		return;
	}

	for (int i = 1; i <= 3 && i <= n; i++) {
		cur.push_back(i);
		bt(n - i, cur);
		cur.pop_back();
	}

	
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> cur;
	bt(n, cur);

	sort(v.begin(), v.end());

	if (k <= v.size()) {
		cout << v[k - 1];
	}
	else {
		cout << -1;
	}
	
}