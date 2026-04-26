// 15886번 내 선물을 받아줘 2
#include<iostream>
using namespace std;

int n, cnt = 0;
char arr[1001];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	for (int i = 0; i < n-1; i++) {
		if (arr[i] == 'E' && arr[i + 1] == 'W') {
			cnt++;
		}
	}

	cout << cnt;
}
