// 3566번 대형 스크린
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int rh, rv, sh, sv, sz;
    cin >> rh >> rv >> sh >> sv;
    cin >> sz;

    int min_price = 1000000000;

    for (int i = 0; i < sz; i++) {
        int rhi, rvi, shi, svi, pi;
        cin >> rhi >> rvi >> shi >> svi >> pi;

        int horizontal = max((int)ceil((double)rh / rhi), (int)ceil((double)sh / shi));
        int vertical = max((int)ceil((double)rv / rvi), (int)ceil((double)sv / svi));
        min_price = min(min_price, horizontal * vertical * pi);

        horizontal = max((int)ceil((double)rh / rvi), (int)ceil((double)sh / svi));
        vertical = max((int)ceil((double)rv / rhi), (int)ceil((double)sv / shi));
        min_price = min(min_price, horizontal * vertical * pi);
    }

    cout << min_price;
}