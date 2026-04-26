// 15565번 귀여운 라이언
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> doll_list;
vector<int> count_list;

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int doll;
		cin >> doll;
		if (doll == 1) {
			doll_list.push_back(i);
		}
	}

	if (doll_list.size() < k) {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < doll_list.size() - k + 1; i++) {
		count_list.push_back(doll_list[k-1+i] - doll_list[i] + 1);
	}

	if (!count_list.empty()) {
		cout << *min_element(count_list.begin(), count_list.end());
	}
	else {
		cout << -1;
	}

	return 0;
 
}