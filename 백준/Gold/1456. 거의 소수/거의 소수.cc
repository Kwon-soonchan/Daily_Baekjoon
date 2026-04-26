// 1456번 거의 소수
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;

	vector<bool> isPrime(sqrt(b) + 1, true);
	isPrime[0] = isPrime[1] = false;

	for (long long i = 2; i * i <= sqrt(b); i++) {
		if (isPrime[i]) {
			for (long long j = i * i; j <= sqrt(b); j += i) {
				isPrime[j] = false;
			}
		}
	}

	int count = 0;

	for (long long i = 2; i <= sqrt(b); i++) {
		if (isPrime[i]) {
			int j = 2;
			while (pow(i, j) <= b) {
				if (pow(i, j) >= a) {
					count++;
				}
				j++;
			}
		}
	}
	cout << count;
}