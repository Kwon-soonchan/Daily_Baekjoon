#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	map<string, string, greater<string>> m;
	for (int i = 0; i < n; i++) {
		string name, state;
		cin >> name >> state;
		
		if (state == "enter") {
			m.insert({ name,state });
		}
		else if (state == "leave") {
			m.erase(name);
		}
	}

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << "\n";
	}
}