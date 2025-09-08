#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

void bfs(int a, int b, int c) {
	queue<vector<int>> q;
	set<vector<int>> visited;
	vector<int> v = { a,b,c };
	sort(v.begin(), v.end());
	q.push(v);
	visited.insert(v);

	while (!q.empty()) {
		int cur_a = q.front()[0];
		int cur_b = q.front()[1];
		int cur_c = q.front()[2];
		q.pop();

		if (cur_a == cur_b && cur_b == cur_c) {
			cout << 1 << endl;
			return;
		}

		// ab
		if (cur_a < cur_b) {
			int next_a = cur_a + cur_a;
			int next_b = cur_b - cur_a;
			vector<int> next_v = { next_a,next_b,cur_c };
			sort(next_v.begin(), next_v.end());
			
			if (visited.find(next_v) == visited.end()) {
				q.push(next_v);
				visited.insert(next_v);
			}
		}
		else {
			int next_a = cur_a - cur_b;
			int next_b = cur_b + cur_b;
			vector<int> next_v = { next_a,next_b,cur_c };
			sort(next_v.begin(), next_v.end());
			
			if (visited.find(next_v) == visited.end()) {
				q.push(next_v);
				visited.insert(next_v);
			}
		}
		// ac
		if (cur_a < cur_c) {
			int next_a = cur_a + cur_a;
			int next_c = cur_c - cur_a;
			vector<int> next_v = { next_a,cur_b,next_c };
			sort(next_v.begin(), next_v.end());
			
			if (visited.find(next_v) == visited.end()) {
				q.push(next_v);
				visited.insert(next_v);
			}
		}
		else {
			int next_a = cur_a - cur_c;
			int next_c = cur_c + cur_c;
			vector<int> next_v = { next_a,cur_b,next_c };
			sort(next_v.begin(), next_v.end());
			
			if (visited.find(next_v) == visited.end()) {
				q.push(next_v);
				visited.insert(next_v);
			}
		}
		// bc
		if (cur_b < cur_c) {
			int next_b = cur_b + cur_b;
			int next_c = cur_c - cur_b;
			vector<int> next_v = { cur_a,next_b,next_c };
			sort(next_v.begin(), next_v.end());
			
			if (visited.find(next_v) == visited.end()) {
				q.push(next_v);
				visited.insert(next_v);
			}
		}
		else {
			int next_b = cur_b - cur_c;
			int next_c = cur_c + cur_c;
			vector<int> next_v = { cur_a,next_b,next_c };
			sort(next_v.begin(), next_v.end());
			
			if (visited.find(next_v) == visited.end()) {
				q.push(next_v);
				visited.insert(next_v);
			}
		}
	}

	cout << 0 << endl;
	return;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	if ((a + b + c) % 3 == 0) {
		bfs(a, b, c);
	}
	else {
		cout << 0 << endl;
		return 0;
	}
}