// 21921번 블로그
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> visit_list;
vector<int> sum_list;

int main() {
	int n, x, sum=0;
	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		int visit;
		cin >> visit;
		visit_list.push_back(visit);
		if (i < x) {
			sum += visit;
		}
	}
	
	for (int i = 0; i < n-x+1; i++) {
		if (i > 0) {
			sum = sum - visit_list[i - 1] + visit_list[i + x - 1];
		}
		sum_list.push_back(sum);
	}

	int max_sum = *max_element(sum_list.begin(), sum_list.end());
	int count_sum = count(sum_list.begin(), sum_list.end(), max_sum);

	if (max_sum == 0) {
		cout << "SAD";
	}
	else {
		cout << max_sum << "\n" << count_sum << endl;
	}
}