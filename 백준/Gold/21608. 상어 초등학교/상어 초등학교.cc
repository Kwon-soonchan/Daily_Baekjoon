// 21608번 상어 초등학교
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool visited[21][21] = { false };
int sit[21][21] = { 0 };
vector <int> student[401];

// 상, 하, 좌, 우를 확인하기 위한 방향 배열
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct shark {
	int near;
	int empty;
	int x, y;


	shark(int a, int b, int c, int d) : near(a), empty(b), x(c), y(d) {}

	bool operator< (const shark& b) const {
		if (near == b.near) {
			if (empty == b.empty) {
				if (x == b.x) {
					return y < b.y;
				}
				else {
					return x < b.x;
				}
			}
			else return empty > b.empty;
		}
		else return near > b.near;
	}
};

int calculateSatisfaction(int n) {
    int totalSatisfaction = 0;

    for (int i = 1; i <= n * n; i++) {
        int satisfaction = 0;
        int likeCount = 0;  // 인접한 칸에 앉은 좋아하는 학생의 수
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (sit[j][k] == i) {  // 학생 i가 앉은 칸을 찾음
                    for (int d = 0; d < 4; d++) {  // 상하좌우 검사
                        int nx = j + dx[d];
                        int ny = k + dy[d];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                            // 인접한 칸에 앉은 학생이 i 학생이 좋아하는 학생인지 확인
                            if (find(student[i].begin(), student[i].end(), sit[nx][ny]) != student[i].end()) {
                                likeCount++;
                            }
                        }
                    }
                    break;  // 학생 i에 대한 처리가 끝났으므로 내부 루프 종료
                }
            }
        }
        // 만족도 계산
        switch (likeCount) {
        case 0: satisfaction = 0; break;
        case 1: satisfaction = 1; break;
        case 2: satisfaction = 10; break;
        case 3: satisfaction = 100; break;
        case 4: satisfaction = 1000; break;
        }
        totalSatisfaction += satisfaction;
    }

    return totalSatisfaction;
}



int main() {
    int n;
    cin >> n;
    int firstStudentNum;
    cin >> firstStudentNum;
    student[firstStudentNum].resize(4);
    for (int j = 0; j < 4; j++) {
        cin >> student[firstStudentNum][j];
    }

    // 첫 번째 학생을 (1,1)에 배치
    sit[1][1] = firstStudentNum;
    visited[1][1] = true;

    // 학생의 선호도 입력 받기 및 자리 배치 (첫 번째 학생 제외)
    for (int idx = 1; idx < n * n; idx++) {
        int num;
        cin >> num;
        student[num].resize(4);
        for (int j = 0; j < 4; j++) {
            cin >> student[num][j];
        }

        // 자리 배치
        vector<shark> positions;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (!visited[r][c]) {
                    int near_cnt = 0, empty_cnt = 0;
                    for (int d = 0; d < 4; d++) {
                        int nx = r + dx[d], ny = c + dy[d];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                            if (visited[nx][ny]) {
                                if (find(student[num].begin(), student[num].end(), sit[nx][ny]) != student[num].end()) {
                                    near_cnt++;
                                }
                            }
                            else {
                                empty_cnt++;
                            }
                        }
                    }
                    positions.push_back(shark(near_cnt, empty_cnt, r, c));
                }
            }
        }
        sort(positions.begin(), positions.end());
        if (!positions.empty()) {
            // 가장 조건에 부합하는 첫 번째 위치에 학생을 배치
            sit[positions[0].x][positions[0].y] = num;
            visited[positions[0].x][positions[0].y] = true;
        }
    }

    cout << calculateSatisfaction(n) << '\n';

}