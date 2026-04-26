#include <iostream>
#include <vector>
using namespace std;

int parent[201];

int find(int n) {
    if (parent[n] == n) {
        return n;
    }
    else {
        return parent[n] = find(parent[n]);
    }
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int check;
            cin >> check;
            if (check == 1) {
                merge(i, j);
            }
        }
    }

    vector<int> v;
    for (int i = 0; i < m; i++) {
        int city;
        cin >> city;
        v.push_back(city);
    }

    int root = find(v[0]);
    bool possible = true;

    for (int i = 1; i < m; i++) {
        if (find(v[i]) != root) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
