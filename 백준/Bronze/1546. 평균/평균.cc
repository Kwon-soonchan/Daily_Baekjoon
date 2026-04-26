#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	int m = 0;
	int score[1000] = {};
	double result = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> score[i];
		if (score[i] > m) {
			m = score[i];
		}
		result += score[i];
	}
	
	result = (result / m * 100) / n;

	cout << result;
}