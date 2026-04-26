// 알쿡 겨울학기 코테 2번 
// 1110번 더하기 사이클
#include<iostream>
using namespace std;

int main() {
	int a, b;
	int count = 0;
	
	cin >> a;
	b = a;

	do
	{
		int x = 0, y = 0, z = 0;

		if (b >= 10 && b <= 99) {
			x = b / 10;
			y = b % 10;
			z = x + y;
			b = (y * 10) + (z % 10);
			count++;
		}
		else if (b <= 9 && b >= 0) {
			x = 0;
			y = b % 10;
			z = x + y;
			b = (y * 10) + (z % 10);
			count++;
		}
	} while (a != b);

	cout << count;
}