#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b, c, result;
	cin >> a >> b >> c;
	result = a * b * c;
	int arr[10] = {};
	string s_result = to_string(result);

	for (char c : s_result) {
		arr[c - '0']++;
	}

	for (int i : arr) {
		cout << i << '\n';
	}
}