// 14888번 연산자 끼워넣기
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> num;
	vector<int> arr;
	vector<int> temp;
	vector<char> cal;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		num.push_back(n);
	}

	for (int i = 0; i < 4; i++) {
		int c;
		cin >> c;

		if (i == 0) {
			for (int j = 0; j < c; j++) {
				cal.push_back('+');
			}
		}
		else if (i == 1) {
			for (int j = 0; j < c; j++) {
				cal.push_back('-');
			}
		}
		else if (i == 2) {
			for (int j = 0; j < c; j++) {
				cal.push_back('*');
			}
		}
		else if (i == 3) {
			for (int j = 0; j < c; j++) {
				cal.push_back('/');
			}
		}
	}

	sort(cal.begin(), cal.end());

	do
	{
		temp = num;

		for (int i = 0; i < cal.size(); i++) {
			if (cal[i] == '+') {
				temp[i+1] = temp[i] + temp[i + 1];
			}
			else if (cal[i] == '-') {
				temp[i+1] = temp[i] - temp[i + 1];
			}
			else if (cal[i] == '*') {
				temp[i+1] = temp[i] * temp[i + 1];
			}
			else if (cal[i] == '/') {
				if (num[i] < 0 && num[i + 1] > 0) {
					temp[i+1] = -(temp[i] / -temp[i + 1]);
				}
				else {
					temp[i+1] = temp[i] / temp[i + 1];
				}
			}
		}
		arr.push_back(temp[N-1]);
	} while (next_permutation(cal.begin(), cal.end()));

	int M = *max_element(arr.begin(), arr.end());
	int n = *min_element(arr.begin(), arr.end());

	cout << M << '\n' << n;
}