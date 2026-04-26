// 6443번 애너그램
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> arr;
vector<char> arr2;

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		arr.push_back(s);
	}

	for (int i = 0; i < arr.size(); i++) {
		arr2.clear();

		for (char c : arr[i]) {
			arr2.push_back(c);
		}
		sort(arr2.begin(), arr2.end());

		do
		{
			for (int j = 0; j < arr2.size(); j++) {
				cout << arr2[j];
			}
			cout << '\n';
		} while (next_permutation(arr2.begin(), arr2.end()));
	}
}