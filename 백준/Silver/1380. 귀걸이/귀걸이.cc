#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    int n;
    int cnt = 1;

    while (true) {
        cin >> n;
        if (n == 0) {
            return 0;
        }

        vector<string> v(n + 1);
        vector<bool> visited(n + 1, false);

        cin.ignore(); // 개행 문자 제거

        for (int i = 0; i < n; i++) {
            getline(cin, v[i + 1]);
        }

        int num;
        char c;

        for (int i = 0; i < 2 * n - 1; i++) {
            cin >> num >> c;
            if (!visited[num]) {
                visited[num] = true;
            }
            else {
                visited[num] = false;
            }
        }


        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                cout << cnt << " " << v[i] << "\n";
                cnt++;
            }
        }
    }
}