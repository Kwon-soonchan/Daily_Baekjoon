#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main() {
	vector<string> words(6);
	for (int i = 0; i < 6; i++) {
		cin >> words[i];
	}

	vector<int> order = { 0,0,0,1,1,1 };
	string dict = "";

	sort(order.begin(), order.end());
	do {
		vector<string> rows;
		vector<string> cols;
		for (int i = 0; i < 6; i++) {
			if (order[i] == 0) {
				rows.push_back(words[i]);
			}
			else {
				cols.push_back(words[i]);
			}
		}
		sort(rows.begin(), rows.end());
		do {
			sort(cols.begin(), cols.end());
			do {
				bool ok = true;
				for (int i = 0; i < 3 && ok; i++) {
					for (int j = 0; j < 3; j++) {
						if (rows[i][j] != cols[j][i]) {
							ok = false;
							break;
						}
					}
				}
				if (ok) {
					string candidate;
					for (auto& r : rows) {
						candidate += r;
					}
					if(dict == "" || candidate < dict) {
						dict = candidate;
					}
				}
			} while (next_permutation(cols.begin(), cols.end()));
		} while (next_permutation(rows.begin(), rows.end()));
	} while (next_permutation(order.begin(), order.end()));

	if (dict == "") {
		cout << 0 << endl;
	}
	else {
		for (int i = 0; i < 9; i += 3) {
			cout << dict.substr(i, 3) << endl;
		}
	}
}