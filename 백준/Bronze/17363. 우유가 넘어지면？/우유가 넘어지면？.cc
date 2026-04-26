#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n, m;
	char a;
	vector <vector <char>> v;
	vector <char> v2;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;
			if (a == '-') {
				a += 79;
			}
			else if (a == '|') {
				a -= 79;
			}
			else if (a == '/') {
				a += 45;
			}
			else if (a == '\\') {
				a -= 45;
			}
			else if (a == '^') {
				a -= 34;
			}
			else if (a == '<') {
				a += 58;
			}
			else if (a == 'v') {
				a -= 56;
			}
			else if (a == '>') {
				a += 32;
			}
			v2.push_back(a);
		}
		v.push_back(v2);
		v2.clear();
	}
	for (int k = m-1; k >= 0; k--) {
		for (int l = 0; l < n; l++) {
			cout << v[l][k];
		}
		cout << '\n';
	}
}