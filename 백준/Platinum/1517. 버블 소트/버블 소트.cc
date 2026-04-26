// 1517번 버블 소트
#include<iostream>
#include<vector>
#include<algorithm>
#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
ll h = 1;
vector <ll> tree;
vector <pii> num;

int init(int start, int end, int node) {
	if (start == end) return tree[node] = 1;
	return tree[node] = init(start, (start + end) / 2, node * 2) + init((start + end) / 2 + 1, end, node * 2 + 1);
}

// 기존코드
//void update(int idx, ll value) {
//	idx += h;
//	tree[idx] = value;
//	while (idx > 1) {
//		idx /= 2;
//		tree[idx] =  tree[idx * 2] + tree[idx * 2 + 1];
//	}
//}

// 수정코드
void update(int start, int end, int idx, int node, int value) {
	if (start > idx || end < idx) return;
	if (start == end) {
		if (start == idx) tree[node] = value;
		return;
	}
	update(start, (start + end) / 2, idx, node * 2, value);
	update((start + end) / 2 + 1, end, idx, node * 2 + 1, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}

ll query(int L, int R, int nodeL, int nodeR, int node) {
	if (nodeR < L || R < nodeL) {
		return 0;
	}
	if (L <= nodeL && nodeR <= R) {
		return tree[node];
	}
	int mid = (nodeL + nodeR) / 2;
	return query(L, R, nodeL, mid, node * 2) + query(L, R, mid + 1, nodeR, node * 2 + 1);
}


int main() {
	fastio;
	cin >> N;
	while (N > h) {
		h <<= 2;
	}
	tree.resize(2 * h);

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		num.push_back({n,i});
	}

	init(0, N-1, 1);
	sort(num.begin(), num.end());

	ll result = 0;

	for (int i = 0; i < N; i++) {
		int sec = num[i].second;
		result += query(0, sec, 0, N-1, 1)-1;
		update(0, N-1, sec, 1, 0);
	}
	cout << result;
}