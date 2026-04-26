#include<iostream>
#include<string>
using namespace std;

int main() {
	string A, B, C, D;
	cin >> A >> B >> C >> D;
	A += B;
	C += D;

	long long n = stol(A) + stol(C);
	cout << n << endl;
}