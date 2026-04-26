#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int n;
	int cnt = 0;

	vector<pair<string,string>> names;

	while (true) {
		cin >> n;
		if (n == 0) {
			return 0;
		}

		cnt++;

		for (int i = 0; i < n; i++) {
			string name;
			string words;
			cin >> name;

			for (int j = 0; j < n - 1; j++) {
				char word;
				cin >> word;
				words += word;
			}

			names.push_back({ name,words });
		}

		cout << "Group " << cnt << "\n";
		bool found = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (names[i].second[j] == 'N') {
					int from = (i - j - 1 + n) % n;
					cout << names[from].first << " was nasty about " << names[i].first << "\n";
					found = true;
				}
			}
		}
		if (!found) cout << "Nobody was nasty\n";
		cout << "\n";
		names.clear();
	}
}