#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int n, d, k, c;
int flag, count, coupon, maxi = 0;
int sushi[300001];
int check[3001];
vector <int> eat;

int main() {
	// n : 접시, d : 초밥종류, k : 연속접시, c : 쿠폰
	cin >> n >> d >> k >> c;

	// 회전벨트 위 초밥
	for (int i = 0; i < n; i++) {
		cin >> sushi[i];
	}
	// 슬라이딩 윈도우
	for (int i = 0; i < n; i++) {
		flag = 0; // 중복된 스시 체크
		coupon = 1; // 쿠폰 스시가 있는지 확인
		for (int j = i; j < i + k; j++) {
			if (check[sushi[j % n]] == 1) { // 이미 먹은 초밥일 경우 중복 수 표시
				flag++;
			}
			else { // 처음 먹어보는 초밥일 경우 체크
				check[sushi[j % n]] = 1;
			}

			if (sushi[j % n] == c) { // 쿠폰 스시가 있는 경우
				coupon = 0;
			}
		}
		maxi = max(maxi, k - flag + coupon); // 연속으로 먹을 수 있는 최대접시 - 중복접시 + 쿠폰스시
		memset(check, 0, sizeof(check)); // 체크 초기화
	}
	cout << maxi;
}