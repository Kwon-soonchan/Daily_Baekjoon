// 5052번 전화번호 목록
#include<iostream>
#include<string>
using namespace std;

struct Trie {
    Trie* ch[10];
    bool endOfWord = false;
    Trie() {
        fill(ch, ch + 10, nullptr);
    }
    // 삽입 과정에서 일관성을 검사하도록 insert 함수를 수정합니다.
    // 일관성이 없으면 false를 반환합니다.
    bool insert(string str, int idx = 0) {
        if (idx == str.size()) {
            endOfWord = true;
            // 현재 노드가 문자열의 끝이면서 자식 노드가 있다면 일관성이 없는 것입니다.
            for (int i = 0; i < 10; ++i) {
                if (ch[i] != nullptr) return false;
            }
            return true;
        }
        int nxt = str[idx] - '0';
        if (ch[nxt] == nullptr) {
            ch[nxt] = new Trie();
        }
        else if (ch[nxt]->endOfWord) { // 현재 문자열이 이미 저장된 문자열의 접두어인 경우
            return false;
        }
        // 다음 문자로 이동합니다.
        return ch[nxt]->insert(str, idx + 1);
    }
    void clear(void) {
        for (int i = 0; i < 10; i++) {
            if (ch[i] != nullptr) {
                ch[i]->clear();
                delete ch[i];
                ch[i] = nullptr; // 삭제 후 nullptr로 설정합니다.
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        Trie* root = new Trie();
        bool consistent = true; // 일관성 여부를 저장하는 변수입니다.

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            if (!root->insert(s)) { // 삽입 과정에서 일관성이 없는 경우
                consistent = false;
            }
        }

        if (consistent) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }

        root->clear();
        delete root;
    }

    return 0;
}
