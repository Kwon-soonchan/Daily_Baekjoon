#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dist[10001];
bool visited[10001];
vector <int> computer[101];
queue <int> q;


void bfs(int start) {
	int count = 0;
	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		//cout << now << '\n';

		for (int i = 0; i < computer[now].size(); i++) {
			int next = computer[now][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
				count++;
			}
		}
	}
	cout << count;
}

int main() {
	int numberOfComputer, pairOfComputer, x, y;

	cin >> numberOfComputer;
	cin >> pairOfComputer;

	for (int i = 0; i < pairOfComputer; i++) {
		cin >> x >> y;
		computer[x].push_back(y);
		computer[y].push_back(x);
	}

	bfs(1);
}