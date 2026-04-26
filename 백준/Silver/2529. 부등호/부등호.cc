#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int k;
char c[10];
bool visited[10];
vector<string> v;

bool isValid(int a, int b, int boo) {
	if (boo == '<') {
		return a < b;
	}
	return a > b;
}

void dfs(int depth, string s) {
	if(depth == k + 1) {
		v.push_back(s);
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (!visited[i]) {
			if (depth == 0 || isValid(s[depth - 1], i + '0', c[depth - 1])) {
				visited[i] = true;
				dfs(depth + 1, s + to_string(i));
				visited[i] = false;
			}
		}
	}
}

int main() {
	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> c[i];
	}

	dfs(0, "");

	sort(v.begin(), v.end());

	cout << v.back() << endl;
	cout << v.front() << endl;
}