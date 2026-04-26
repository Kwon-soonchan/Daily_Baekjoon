#include <iostream>
using namespace std;

// 각 월의 일수 (윤년 아님)
int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

// 윤년 판별 함수
bool isLeap(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

// 날짜를 일수로 변환 (1900-01-01 기준)
int toDays(int y, int m, int d) {
    int days = d;
    for (int year = 1; year < y; ++year)
        days += isLeap(year) ? 366 : 365;
    for (int month = 1; month < m; ++month) {
        if (month == 2 && isLeap(y)) days += 29;
        else days += monthDays[month];
    }
    return days;
}

// 날짜 비교 함수: (y1,m1,d1) <= (y2,m2,d2)
bool dateGreaterOrEqual(int y1, int m1, int d1, int y2, int m2, int d2) {
    if (y1 != y2) return y1 > y2;
    if (m1 != m2) return m1 > m2;
    return d1 >= d2;
}

int main() {
    int cy, cm, cd, ny, nm, nd;
    cin >> cy >> cm >> cd;
    cin >> ny >> nm >> nd;

    // 1000년 후 날짜 계산
    int fy = cy + 1000, fm = cm, fd = cd;

    // 목표일이 1000년 후 날짜 이상이면 gg
    if (dateGreaterOrEqual(ny, nm, nd, fy, fm, fd)) {
        cout << "gg" << endl;
        return 0;
    }

    int start = toDays(cy, cm, cd);
    int end = toDays(ny, nm, nd);

    cout << "D-" << end - start << endl;
}