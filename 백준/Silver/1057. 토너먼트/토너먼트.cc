#include<iostream>
using namespace std;

int main() {
	int n, kim, im, round = 0;
	cin >> n >> kim >> im;

	while (kim != im) {
		round++;

		if (kim % 2 == 1) {
			kim = kim / 2 + 1;
		}
		else{
			kim /= 2;
		}

		if (im % 2 == 1) {
			im = im / 2 + 1;
		}
		else {
			im /= 2;
		}
	}

	cout << round << endl;
}