// 14426번 접두사 찾기
#include<iostream>
#include<string>
using namespace std;

struct Trie {
	Trie* ch[26];
	Trie() {
		fill(ch, ch + 26, nullptr);
	}
	void insert(string str, int idx = 0) { // 기본값을 제공하여 호출 시 idx를 생략할 수 있게 합니다.
		if (idx == str.size()) {
			return;
		}
		int nxt = str[idx] - 'a';
		if (ch[nxt] == NULL) {
			ch[nxt] = new Trie();
		}
		ch[nxt]->insert(str, idx + 1);
	}
	int find(string str, int idx = 0) { // 기본값을 제공하여 호출 시 idx를 생략할 수 있게 합니다.
		if (idx == str.size()) {
			return true;
		}
		int nxt = str[idx] - 'a';
		if (ch[nxt] == NULL) {
			return false;
		}
		return ch[nxt]->find(str, idx + 1);
	}
	void clear(void) {
		for (int i = 0; i < 26; i++) {
			if (ch[i] != NULL) {
				ch[i]->clear();
				delete ch[i];
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	Trie* root = new Trie(); // Trie의 루트 노드를 생성합니다.

	string s;
	
	for (int i = 0; i < n; i++) {
		cin >> s;
		root->insert(s); // s1 문자열들을 Trie에 삽입합니다.
	}

	int count = 0; // s2 문자열 중 Trie에 존재하는 문자열의 개수를 저장할 변수입니다.
	
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (root->find(s)) { // s2 문자열이 Trie에 존재하는지 확인합니다.
			count++;
		}
	}

	cout << count << '\n'; // s2 문자열 중 Trie에 존재하는 문자열의 개수를 출력합니다.

	root->clear();

	delete root; // 동적으로 할당된 메모리를 해제합니다. 실제로는 모든 노드를 반복적으로 삭제하는 과정이 필요합니다.

	return 0;
}
