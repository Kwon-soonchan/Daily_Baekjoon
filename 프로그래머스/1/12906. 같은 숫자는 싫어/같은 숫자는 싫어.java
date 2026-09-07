// 입력 크기: arr크기 N
// 풀이: 배열 arr를 반복문으로 돌면서 처음 마주치는 값들을 새로운 배열에 추가한 뒤, 새로운 배열 출력
// 예상 시간복잡도: O(2N)

import java.util.*;

public class Solution {
    public List<Integer> solution(int []arr) {
        List<Integer> answer = new ArrayList<Integer>();
        answer.add(arr[0]);
        for(int i=1;i<arr.length;i++) {
            if(arr[i] == arr[i-1]) {
                continue;
            }
            else {
                answer.add(arr[i]);
            }
        }        

        return answer;
    }
}