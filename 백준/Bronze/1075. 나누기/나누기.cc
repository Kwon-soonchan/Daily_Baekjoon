#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string n;
	int f;
	cin >> n >> f;

	for (int i = 0; i <= 99; i++) {
		string add = "";
		if (to_string(i).length() == 1) {
			add = "0" + to_string(i);
		}
		else {
			add = to_string(i);
		}

		n.replace(n.length() - 2, n.back(), add);

		if (stoi(n) % f == 0) {
			cout << add;
			return 0;
		}
	}
}