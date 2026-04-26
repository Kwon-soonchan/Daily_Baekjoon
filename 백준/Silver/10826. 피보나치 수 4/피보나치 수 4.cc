#include<iostream>
#include<vector>
#include<string>
using namespace std;
 
string add(string a, string b) {
	string result = "";
	int carry = 0;;

	while (a.length() < b.length()) {
		a = "0" + a;
	}
	while (b.length() < a.length()) {
		b = "0" + b;
	}

	for (int i = a.length() - 1; i >= 0; i--) {
		int sum = (a[i]-'0') + (b[i] - '0') + carry;
		carry = sum / 10;
		result = to_string(sum % 10) + result;
	}

	if (carry) {
		result = '1' + result;
	}

	return result;
}

int main() {
	int n;
	cin >> n;

	vector<string> dp(n + 2);
	dp[0] = "0";
	dp[1] = "1";
	
	for (int i = 2; i <= n; i++) {
		dp[i] = add(dp[i - 1], dp[i - 2]);
	}

	cout << dp[n] << endl;
}