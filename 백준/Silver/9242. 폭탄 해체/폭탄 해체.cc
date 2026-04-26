#include<iostream>
#include<string>
using namespace std;

char zero[5][3] = {
    {'*','*','*'},
    {'*',' ','*'},
    {'*',' ','*'},
    {'*',' ','*'},
    {'*','*','*'}
};

char one[5][3] = {
    {' ',' ','*'},
    {' ',' ','*'},
    {' ',' ','*'},
    {' ',' ','*'},
    {' ',' ','*'}
};

char two[5][3] = {
    {'*','*','*'},
    {' ',' ','*'},
    {'*','*','*'},
    {'*',' ',' '},
    {'*','*','*'}
};

char three[5][3] = {
    {'*','*','*'},
    {' ',' ','*'},
    {'*','*','*'},
    {' ',' ','*'},
    {'*','*','*'}
};

char four[5][3] = {
    {'*',' ','*'},
    {'*',' ','*'},
    {'*','*','*'},
    {' ',' ','*'},
    {' ',' ','*'}
};

char five[5][3] = {
    {'*','*','*'},
    {'*',' ',' '},
    {'*','*','*'},
    {' ',' ','*'},
    {'*','*','*'}
};

char six[5][3] = {
    {'*','*','*'},
    {'*',' ',' '},
    {'*','*','*'},
    {'*',' ','*'},
    {'*','*','*'}
};

char seven[5][3] = {
    {'*','*','*'},
    {' ',' ','*'},
    {' ',' ','*'},
    {' ',' ','*'},
    {' ',' ','*'}
};

char eight[5][3] = {
    {'*','*','*'},
    {'*',' ','*'},
    {'*','*','*'},
    {'*',' ','*'},
    {'*','*','*'}
};

char nine[5][3] = {
    {'*','*','*'},
    {'*',' ','*'},
    {'*','*','*'},
    {' ',' ','*'},
    {'*','*','*'}
};

char word[5][31];
char block[5][3];

bool isSame(char a[5][3], char b[5][3]) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 3; j++)
            if (a[i][j] != b[i][j])
                return false;
    return true;
}

int main() {
	string s;
    string num = "";

	for (int i = 0; i < 5; i++) {
		getline(cin, s);

		for (int j = 0; j < s.length(); j++) {
			word[i][j] = s[j];
		}
	}
	
	for (int i = 0; i < s.length(); i += 4) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 3; k++) {
                block[j][k] = word[j][i + k];
            }
        }

        if (isSame(block, zero)) {
            num += '0';
        }
        else if (isSame(block, one)) {
            num += '1';
        }
        else if (isSame(block, two)) {
            num += '2';
        }
        else if (isSame(block, three)) {
            num += '3';
        }
        else if (isSame(block, four)) {
            num += '4';
        }
        else if (isSame(block, five)) {
            num += '5';
        }
        else if (isSame(block, six)) {
            num += '6';
        }
        else if (isSame(block, seven)) {
            num += '7';
        }
        else if (isSame(block, eight)) {
            num += '8';
        }
        else if (isSame(block, nine)) {
            num += '9';
        }
	}

    int number = stoi(num);

    if (number % 6 == 0) {
        cout << "BEER!!" << endl;
    }
    else {
        cout << "BOOM!!" << endl;
    }
}