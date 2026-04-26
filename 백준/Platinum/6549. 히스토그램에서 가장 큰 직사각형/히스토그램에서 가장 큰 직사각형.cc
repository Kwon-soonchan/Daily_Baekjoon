// 6549번 히스토그램에서 가장 큰 직사각형
#include<iostream>
#include<vector>
#include<string>
#define fastio  cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;

int N;
ll result;
ll h = 1;
vector <ll> tree;
vector <ll> num;

int update(int start, int end, int node) {
	// 리프노드라면 입력받은 인덱스로 저장
	if (start == end) return tree[node] = start;
	// 아니라면 값이 더 작은 자식의 인덱스를 저장
	int left = update(start, (start + end) / 2, node * 2);
	int right = update((start + end) / 2 + 1, end, node * 2 + 1);
	return tree[node] = num[left] < num[right] ? left : right;
}

ll query(int start, int end, int L, int R, int node) {
	// 범위에 포함되면 노드값 반환
	if (L <= start && end <= R) {
		return tree[node];
	}
	// 아예 범위에 포함 안되면 아예 큰 값으로 바꿔버림
	if (end < L || R < start) {
		return 2e9;
	}
	int mid = (start + end) / 2;
	int left = query(start, mid, L, R, node * 2);
	int right = query(mid + 1, end, L, R, node * 2 + 1);
	// 범위에 포함되거나 적당히 겹칠때 작은 자식 인덱스 저장
	if (left == 2e9) {
		return right;
	}
	else if (right == 2e9) {
		return left;
	}
	else {
		return num[left] < num[right] ? left : right;
	}

}

void solve(ll left, ll right) {
	if (left > right) return;
	
	// 가장 낮은 인덱스 구하기
	ll index = query(0, N - 1, left, right, 1);
	// 최대넓이 갱신
	result = max(result, num[index]*(right - left + 1));
	// 좌우 한번씩 돌면서 다른 직사각형 찾기
	solve(left, index - 1);
	solve(index + 1, right);
}

int main() {
	fastio;
	string s;
	while (true) {
		tree.clear();
		num.clear();
		result = 0;
		h = 1;
		cin >> s;
		if (s == "0") {
			break;
		}
		N = stoi(s);

		while (N > h) {
			h <<= 2;
		}
		tree.resize(2 * h);
		num.resize(2 * h);

		for (int i = 0; i < N; i++) {
			cin >> num[i];
		}

		update(0, N - 1, 1);
		
		solve(0, N - 1);

		cout << result << '\n';
	}
}