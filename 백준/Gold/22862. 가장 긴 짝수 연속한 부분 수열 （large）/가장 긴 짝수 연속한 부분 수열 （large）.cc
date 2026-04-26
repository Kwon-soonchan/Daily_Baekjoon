// 22862번 가장 긴 짝수 연속한 부분 수열(large)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		if (s % 2 == 1) {
			v.push_back(1);
		}
		else {
			v.push_back(2);
		}
	}

	int st = 0, en = 0;
	int result = 0, len = 0, count = 0;

	while (en < n) {

		if (v[en] == 2) {
			en++;
			len++;
			result = max(result, len - count);
		}
		else {
			if (count < k) {
				count++;
				len++;
				result = max(result, len - count);
				en++;
			}
			else {
				if (st < en) {
					if (v[st] == 1) {
						count--;
					}
					st++;
					len--;
				}
				else {
					st++;
					en++;
				}
			}
		}
	}
	cout << result;
}