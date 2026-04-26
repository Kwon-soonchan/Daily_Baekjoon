// 2164번 카드2
#include<iostream>
#include<queue>
using namespace std;

int card(int n) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (q.size() > 1) {
        q.pop();

        if (!q.empty()) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }

    return q.front();
}

int main() {
    int n;
    cin >> n;
    cout << card(n);
}