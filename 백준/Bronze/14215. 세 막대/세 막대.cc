#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;
	vector<int> line(3);
	cin >> line[0] >> line[1] >> line[2];
	sort(line.begin(), line.end());

	while (line[2] >= line[1]+line[0]) {
		line[2]--;
		sort(line.begin(), line.end());
	}

	cout << line[0] + line[1] + line[2] << endl;
	
}