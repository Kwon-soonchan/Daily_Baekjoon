#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	string s;
	cin >> s;
	stack<char> st;
	string result = "";

	for (char c : s) {
		if (c >= 'A' && c <= 'Z') {
			result += c;
		}
		else if (c == '(') {
			st.push(c);
		}
		else if(c == ')') {
			while (!st.empty() && st.top() != '(') {
				result += st.top();
				st.pop();
			}
			st.pop();
		}
		else {
			while (!st.empty()) {
				char top = st.top();
				if (top == '(') {
					break;
				}
				if ((c == '+' || c == '-') || ((c == '*' || c == '/') && (top == '*' || top == '/'))) {
					result += top;
					st.pop();
				}
				else {
					break;
				}
			}
			st.push(c);
		}
	}

	while (!st.empty()) {
		result += st.top();
		st.pop();
	}
	cout << result << endl;
}