// 입력 크기: 100*100
// 풀이: 이중반복문
// 예상 시간복잡도: n^2

class Solution {
    public String solution(String[] my_strings, int[][] parts) {
        String answer = "";
        int str_len = my_strings.length;
        for(int i=0;i<str_len;i++) {
            int s = parts[i][0];
            int e = parts[i][1];
            
            for(int j=s;j<=e;j++) {
                answer += my_strings[i].charAt(j);
            }
        }
        return answer;
    }
}