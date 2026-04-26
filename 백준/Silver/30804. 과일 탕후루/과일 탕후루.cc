#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> fruits(n);

	for (int i = 0; i < n; i++) {
		cin >> fruits[i];
	}

	unordered_map<int, int> count;
	int left = 0;
	int max_len = 0;
	
	for (int right = 0; right < n; right++) {
		count[fruits[right]]++;
		
		while (count.size() > 2) {
			count[fruits[left]]--;
			if (count[fruits[left]] == 0) {
				count.erase(fruits[left]);
			}
			left++;
		}
		max_len = max(max_len, right - left + 1);
	}
	cout << max_len << endl;
}