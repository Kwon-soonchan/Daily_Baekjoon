// N = 원본 배열의 길이
// C = commands의 개수
// K = 한 command에서 잘라낸 부분 배열의 최대 길이
// 풀이:
// 예상 시간복잡도:O(C × K log K)
// 예상 공간복잡도:O(K)

import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int t = commands.length;
        int[] answer = new int[t];
        
        for(int i=0;i<t;i++) {
            int[] copied = Arrays.copyOfRange(array, commands[i][0]-1, commands[i][1]);
            Arrays.sort(copied);
            
            answer[i] = copied[commands[i][2]-1];
        }
        
        return answer;
    }
}