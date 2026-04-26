//#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int n,tmp, flag= false;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    if (n < 0) {
        n = -1 * n;
        flag = true;
    }
    vector<int> arr;
    while (n != 0) {
        arr.push_back(n % 3);
        n = n / 3;
    }
    arr.push_back(0);
    vector<int> arr2;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] >= 2) {
            arr[i + 1] += 1;
            arr[i] -= 3;
        }
    }
    if (flag) {
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = -1 * arr[i];
        }
    }
    if (arr[arr.size() - 1] != 0) {
        if (arr[arr.size() - 1] == 1)
            cout << 1;
        else
            cout << 'T';
    }
        
    for (int i = arr.size() - 2; i >= 0; --i) {
        if (arr[i] == 1)
            cout << 1;
        else if (arr[i] == 0)
            cout << 0;
        else cout << 'T';
    }
    return 0;
}