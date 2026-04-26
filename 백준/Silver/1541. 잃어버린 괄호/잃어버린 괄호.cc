#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	string num;
	vector<int> nums;
	vector<char> giho;

	for (char c : s) {
		if (c == '-' || c == '+') {
			nums.push_back(stoi(num));
			num.clear();
			giho.push_back(c);
		}
		else {
			num += c;
		}
	}
	nums.push_back(stoi(num));

	int result = nums[0];
	bool minus = false;

	for (int i = 0; i < giho.size(); i++) {
		if (giho[i] == '-') {
			minus = true;
		}
		if (minus) {
			result -= nums[i + 1];
		}
		else {
			result += nums[i + 1];
		}
	}
	cout << result << endl;
}