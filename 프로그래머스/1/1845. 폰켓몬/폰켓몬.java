// 이 문제에서 필요한 것은 각 종류의 등장 횟수인가?
// 아니면 서로 다른 종류의 개수인가? -> 서로 다른 종류의 갯수
// HashSet을 쓰면 어떤 정보가 자동으로 정리되는가? -> 중복 제거
// N = nums의 길이
// 풀이:기존 배열의 길이의 반 vs set의 길이 중에 작은것
// 예상 시간복잡도:O(N)
// 예상 공간복잡도:O(N)

import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        int halfNum = nums.length / 2;
        Set<Integer> s = new HashSet<>();
        
        for(int n : nums) {
            s.add(n);
        }
        
        int sLen = s.size();
        
        if(halfNum > sLen) {
            answer = sLen;
        }
        else {
            answer = halfNum;
        }
        
        return answer;
    }
}