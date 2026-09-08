// N = 문자열 s의 길이
// 풀이:반복문을 사용해서 s를 돌면서 (와 )를 체크
// 예상 시간복잡도:O(N)
// 예상 공간복잡도:s랑 stack의 크기의 합

import java.util.Deque;
import java.util.ArrayDeque;

class Solution {
    boolean solution(String s) {
        boolean answer = false;
        int Lcnt = 0;
        int Rcnt = 0;

        for(int i=0;i<s.length();i++) {
            if(s.charAt(i) == '(') {
                Lcnt++;
            }
            else if(s.charAt(i) == ')') {
                Rcnt++;
            }
            
            if(Lcnt - Rcnt < 0) {
                answer = false;
                break;
            }
        }
        if(Lcnt - Rcnt == 0) {
            answer = true;
        }

        return answer;
    }
}