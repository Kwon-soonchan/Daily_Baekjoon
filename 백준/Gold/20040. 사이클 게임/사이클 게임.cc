#include <iostream>
using namespace std;

int parent[500'001];

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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m;
    cin >> n >> m;

    int cycleCheck = 0;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        if (find(a) == find(b)) {
            cycleCheck = i;
            break;
        }
        else {
            merge(a, b);
        }
    }

    if (cycleCheck > 0) {
        cout << cycleCheck;
    }
    else {
        cout << 0;
    }
}