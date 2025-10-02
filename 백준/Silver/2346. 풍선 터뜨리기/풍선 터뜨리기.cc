#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int balloon;
		cin >> balloon;
		v.push_back({ balloon, i + 1 });
	}

	int idx = 0;

	while (true) {
		cout << v[idx].second << " ";

		int dist = v[idx].first;

		v.erase(v.begin() + idx);

		if (v.empty()) {
			break;
		}

		if (dist > 0) {
			idx = (idx + dist - 1) % v.size();
		}
		else {
			int new_size = v.size();

			idx = (idx + dist % new_size + new_size) % new_size;
		}
	}
}