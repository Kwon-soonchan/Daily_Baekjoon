// 4949번 균형잡힌 세상
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	string s;

	while (true) {
		getline(cin, s);
		if (s == ".") {
			break;
		}

		stack<char> st;
		bool flag = true;

		for (char c : s) {
			if (c == '(' || c == '[') {
				st.push(c);
			}
			else if (c == ')') {
				if (st.empty() || st.top() != '(') {
					flag = false;
					break;
				}
				st.pop();
			}
			else if (c == ']') {
				if (st.empty() || st.top() != '[') {
					flag = false;
					break;
				}
				st.pop();
			}
		}
		if (!st.empty()) {
			flag = false;
		}
		cout << (flag ? "yes" : "no") << '\n';
	}
}