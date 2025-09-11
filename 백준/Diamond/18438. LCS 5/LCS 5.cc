#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// O(M) 공간을 사용해 LCS 점수 '배열'(마지막 행)을 반환하는 함수
vector<int> getLCS_scores(const string& s1, const string& s2) {
    int n = s1.length();
    int m = s2.length();

    // DP 테이블의 두 행만 유지 (공간 최적화)
    vector<int> prev_row(m + 1, 0);
    vector<int> current_row(m + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                current_row[j] = prev_row[j - 1] + 1;
            }
            else {
                current_row[j] = max(current_row[j - 1], prev_row[j]);
            }
        }
        prev_row = current_row; // 현재 행을 다음 루프의 이전 행으로 업데이트
    }
    return prev_row; // 최종 계산된 마지막 행을 반환
}

// Hirschberg 알고리즘의 메인 재귀 함수
string hirschberg(const string& s1, const string& s2) {
    int n = s1.length();
    int m = s2.length();

    // --- 기저 사례 (Base Cases) ---
    // 1. 어느 한 문자열이 비어있으면, LCS는 빈 문자열
    if (n == 0 || m == 0) {
        return "";
    }

    // 2. s1의 길이가 1이면, s2에서 s1[0] 문자가 있는지 찾아보고 결과를 반환
    if (n == 1) {
        // s2.find(s1[0])는 s2에서 s1[0]을 찾으면 그 위치를, 못찾으면 string::npos를 반환
        if (s2.find(s1[0]) != string::npos) {
            return s1;
        }
        return "";
    }

    // --- 분할 (Divide) ---
    int mid = n / 2;
    string s1_prefix = s1.substr(0, mid);
    string s1_suffix = s1.substr(mid);

    // --- 최적 분할 지점 'k' 찾기 ---
    // s1_suffix와 s2는 뒤집어서 계산해야 함
    string s1_suffix_rev = s1_suffix;
    reverse(s1_suffix_rev.begin(), s1_suffix_rev.end());
    string s2_rev = s2;
    reverse(s2_rev.begin(), s2_rev.end());

    // 정방향(prefix)과 역방향(suffix)의 점수 배열 계산
    vector<int> scores_prefix = getLCS_scores(s1_prefix, s2);
    vector<int> scores_suffix = getLCS_scores(s1_suffix_rev, s2_rev);

    int max_sum = -1;
    int optimal_k = -1;

    for (int k = 0; k <= m; k++) {
        // 역방향 점수 배열은 뒤에서부터 인덱싱해야 함 (scores_suffix[m-k])
        if (scores_prefix[k] + scores_suffix[m - k] > max_sum) {
            max_sum = scores_prefix[k] + scores_suffix[m - k];
            optimal_k = k;
        }
    }

    // --- 정복 (Conquer) ---
    // 찾은 최적의 k를 기준으로 문제를 두 개의 작은 문제로 나누어 재귀 호출
    string lcs_prefix = hirschberg(s1_prefix, s2.substr(0, optimal_k));
    string lcs_suffix = hirschberg(s1_suffix, s2.substr(optimal_k));

    // 두 작은 문제의 결과를 합쳐서 반환
    return lcs_prefix + lcs_suffix;
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    string result_lcs = hirschberg(s1, s2);

    cout << result_lcs.length() << "\n";
    if (!result_lcs.empty()) {
        cout << result_lcs << "\n";
    }

    return 0;
}