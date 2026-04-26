// 10814번 나이순 정렬
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<pair<int, string>, int>> human;

	for (int i = 0; i < n; i++) {
		int age;
		string name;
		cin >> age >> name;

		human.push_back({ { age,name },i });
	}

	sort(human.begin(), human.end(), [](const auto& a, const auto& b) {
		if (a.first.first != b.first.first) {
			return a.first.first < b.first.first;
		}
		return a.second < b.second;
	});

	for (int i = 0; i < n; i++) {
		cout << human[i].first.first << ' ' << human[i].first.second << '\n';
	}
}