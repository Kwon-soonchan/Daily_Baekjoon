#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;

	// 나머지를 n으로 나눠도 되는걸 이용한 방법
	while (cin >> n) {
		int remainder = 1 % n;
		int length = 1;

		while (remainder != 0) {
			remainder = (remainder * 10 + 1) % n;
			length++;
		}
		cout << length << endl;
	}

	// 11부터 시작해서 1씩 늘려가면서 n으로 나누는 방법
	//while (cin >> n) {
	//	string s = "11";
	//	while (true) {
	//		long long x = stol(s);
	//		if (x % n == 0) {
	//			cout << s.length() << endl;
	//			break;
	//		}
	//		else {
	//			s += "1";
	//		}
	//	}
	//}


	// n의 배수를 다 구하는 방법
	//while (cin >> n) {
	//	int x = n;
	//	while (true) {
	//		string s = to_string(n);
	//		bool isOne = true;

	//		for (char c : s) {
	//			if (c != '1') {
	//				isOne = false;
	//				break;
	//			}
	//		}
	//		if (isOne) {
	//			cout << s.length() << endl;
	//			return 0;
	//		}
	//		else {
	//			x += n;
	//		}
	//	}
	//}
}