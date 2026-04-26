#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int>A(n);
	vector<int>B(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}

	int s = 0;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>()); // B를 내림차순으로 정렬

	for (int i = 0; i < n; i++) {
		s += A[i] * B[i];
	}

	cout << s << endl;
}