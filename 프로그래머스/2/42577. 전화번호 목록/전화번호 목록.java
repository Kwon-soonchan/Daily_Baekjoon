// N = 전화번호의 개수
// L = 전화번호 한 개의 최대 길이
// 풀이: hashset의 기능인 contains()를 사용하기.
// 예상 시간복잡도: O(NxL^2)
// 예상 공간복잡도: O(N)

import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        
        HashSet<String> set = new HashSet<>();
        for(String s : phone_book) {
            set.add(s);
        }
        
        for(String phone : phone_book) {
            int size = phone.length();
            for(int i=1;i<size;i++) {
                String prefix = phone.substring(0,i);
                
                if(set.contains(prefix)) {
                    return false;
                }
            }
        }
        
        return answer;
    }
}