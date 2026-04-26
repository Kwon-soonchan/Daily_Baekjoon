#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> v(n);
	vector<int> result(n, -1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	stack<int> st;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && v[st.top()] < v[i]) {
			result[st.top()] = v[i];
			st.pop();
		}
		st.push(i);
	}
	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
}