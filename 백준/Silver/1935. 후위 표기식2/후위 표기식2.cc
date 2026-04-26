#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;

	vector<double> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	double result = 0.0;
	stack<double> st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '+') {
			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();
			st.push(a + b);
		}
		else if (s[i] == '-') {
			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();
			st.push(b - a);
		}
		else if (s[i] == '*') {
			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();
			st.push(a * b);
		}
		else if (s[i] == '/') {
			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();
			st.push(b / a);
		}
		else {
			st.push(v[s[i]-'A']);
		}
	}
	result = st.top();
	cout << fixed;
	cout.precision(2);
	cout << result << endl;
}