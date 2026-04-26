#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {

		vector<int> scores(5, 0);
		for (int i = 0; i < 5; i++) {
			cin >> scores[i];
		}
		sort(scores.begin(), scores.end());

		scores.erase(scores.begin());
		scores.pop_back();

		if (scores[0] + 4 <= scores[2]) {
			cout << "KIN" << "\n";
		}
		else {
			cout << scores[0] + scores[1] + scores[2] << "\n";
		}
	}
}