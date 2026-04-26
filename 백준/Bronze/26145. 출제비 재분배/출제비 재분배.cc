// 알쿡 겨울학기 코테 3번 
// 26145번 출제비 재분배
#include<iostream>
using namespace std;

int s_list[100001];
int t_list[100001];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s_list[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + m; j++) {
			int t;
			cin >> t;
			t_list[j] += t;
			s_list[i] -= t;
		}
		t_list[i] += s_list[i];
	}
	for (int i = 0; i < n + m; i++) {
		cout << t_list[i] << ' ';
	}
}
 