// 26082번 WARBOY
#include<iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int gasungbi = b / a;
	int gasungbi_warboy = gasungbi * 3;
	int warboy = c * gasungbi_warboy;

	cout << warboy;
}