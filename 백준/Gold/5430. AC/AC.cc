#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--) {
		int n;
		bool error_check = false;
		bool is_reversed = false;
		string p, nums;
		vector<int> num;
		cin >> p >> n >> nums;

		string s = "";
		for (char c : nums) {
			if (isdigit(c)) {
				s += c;
			}
			if (c == ',') {
				num.push_back(stoi(s));
				s = "";
			}
		}
		if (s != "") {
			num.push_back(stoi(s));
		}

		for (char c : p) {
			if (c == 'R') {
				if (is_reversed) {
					is_reversed = false;
				}
				else {
					is_reversed = true;
				}
			}
			else if (c == 'D') {
				if (num.size() == 0) {
					error_check = true;
					
				}
				else {
					if (is_reversed) {
						num.pop_back();
					}
					else {
						num.erase(num.begin());
					}
				}
			}
		}
		if (error_check) {
			cout << "error" << endl;
		}
		else {
			cout << "[";
			if (!num.empty()) {
				if (is_reversed) {
					cout << num[num.size() - 1];
					for (int i = num.size()-2; i >= 0; i--) {
						cout << "," << num[i];
					}
				}
				else {
					cout << num[0];
					for (int i = 1; i < num.size(); i++) {
						cout << "," << num[i];
					}
				}
			}
			cout << "]" << endl;
		}
	}
}