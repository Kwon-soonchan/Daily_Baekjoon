// 28702번 FizzBuzz
#include <iostream>
#include <string>
#include <vector>
#include<cctype>
using namespace std;

string fizzbuzz(int i) {
    if (i % 3 == 0 && i % 5 == 0) {
        return "FizzBuzz";
    }
    if (i % 3 == 0) {
        return "Fizz";
    }
    if (i % 5 == 0) {
        return "Buzz";
    }

    return to_string(i);
}

int main() {
    vector<string> input(3);

    for (int i = 0; i < 3; i++) {
        cin >> input[i];
    }

    // 숫자가 있는지 확인
    for (int i = 0; i < 3; ++i) {
        if (isdigit(input[i][0])) {
            int val = stoi(input[i]);
            int start = val - i;
            cout << fizzbuzz(start + 3) << '\n';
            return 0;
        }
    }

    for (int i = 1; i <= 100000000; i++) {
        if (fizzbuzz(i) == input[0] &&
            fizzbuzz(i + 1) == input[1] &&
            fizzbuzz(i + 2) == input[2]) {
            cout << fizzbuzz(i + 3) << '\n';
            break;
        }
    }
}