#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, taesoo, p;
    cin >> n >> taesoo >> p;

    vector<int> scores(n);
    for (int i = 0; i < n; ++i) {
        cin >> scores[i];
    }

    // 태수 점수 맨 뒤에 추가 (동점자 중 가장 나중에 들어온 걸로 처리)
    scores.push_back(taesoo);

    // 내림차순 정렬
    sort(scores.begin(), scores.end(), greater<int>());

    int rank = 1;
    int cur_rank = 1;
    int cnt = 1;

    for (int i = 0; i < scores.size(); ++i) {
        if (i > 0 && scores[i] != scores[i - 1]) {
            cur_rank = i + 1;
        }

        // 동점자 중 맨 뒤에 있는 게 태수라고 가정 (== 마지막 등장)
        if (scores[i] == taesoo) {
            // 태수가 p등보다 뒤면 진입 불가
            if (i >= p) {
                cout << -1 << endl;
                return 0;
            }
            rank = cur_rank;
        }
    }

    cout << rank << endl;
}
