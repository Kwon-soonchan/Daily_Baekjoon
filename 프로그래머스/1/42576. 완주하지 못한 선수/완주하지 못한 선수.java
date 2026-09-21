// N = participant의 길이
// M = completion의 길이
// 풀이: 참가 횟수를 Map에 기록하고 완주 횟수를 차감한 뒤, 값이 1인 이름을 반환한다.
// 예상 시간복잡도: 평균 O(N + M), 단순화하면 평균 O(N)
// 예상 공간복잡도: O(N)

import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        
        Map<String, Integer> m = new HashMap<>();
        
        for(String name : participant) {
            m.put(name, m.getOrDefault(name, 0)+1);
        }
        
        for(String name : completion) {
            m.put(name, m.getOrDefault(name, 0)-1);
        }
        
        for(Map.Entry<String, Integer> entry : m.entrySet()) {
            if(entry.getValue() == 1) {
                answer = entry.getKey();
                break;
            }
        }
        return answer;
    }
}