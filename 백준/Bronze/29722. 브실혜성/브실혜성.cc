// 29722번 브실혜성
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<iomanip>
using namespace std;

vector<string> split(string str, char Delimiter) {
    istringstream iss(str);             
    string buffer;                      

    vector<string> result;

    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);              
    }

    return result;
}

int main() {
	int y, m, d, n;
	string date;

	cin >> date;
	cin >> n;

    vector<string> result = split(date, '-'); 

    y = stoi(result[0]);
    m = stoi(result[1]);
    d = stoi(result[2]);

    d += n;
    while (d > 30) {
        d -= 30;
        m++;
        if (m > 12) {
            m = 1;
            y++;
        }
    }

    cout << setfill('0') << setw(4) << y << '-';
    cout << setw(2) << m << '-';
    cout << setw(2) << d;
}