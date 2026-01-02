import static java.lang.Character.isDigit;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String s = br.readLine();

        StringBuilder tempNum = new StringBuilder(); // 현재 만들고 있는 숫자
        int result = 0; // 누적 결과값
        char lastOp = ' '; // 이전에 등장했던 연산자 (대기 중인 연산자)
        boolean isFirst = true; // 첫 번째 숫자인지 확인용
        boolean printed = false; // 출력이 한 번이라도 됐는지 확인 (문제 조건상 필요 없지만 디버깅용)

        for (char c : s.toCharArray()) {
            if (isDigit(c)) {
                // 1. 숫자면 문자열을 계속 이어 붙임
                tempNum.append(c);
            } else {
                // 2. 연산자(S, M, U, P, C)가 나오면, 지금까지 모은 숫자를 처리해야 함
                if (tempNum.length() > 0) {
                    int num = Integer.parseInt(tempNum.toString());

                    if (isFirst) {
                        result = num; // 첫 숫자는 그대로 결과값이 됨
                        isFirst = false;
                    } else {
                        // 이전 연산자가 있으면 계산 수행
                        result = calc(result, lastOp, num);
                    }
                    tempNum.setLength(0); // 숫자 버퍼 비우기
                }

                // 3. 현재 문자에 따라 처리
                if (c == 'C') {
                    // C는 출력만 함 (연산자로 저장되지 않음)
                    bw.write(result + " ");
                    printed = true;
                } else {
                    // S, M, U, P는 다음 숫자를 위해 '대기 연산자'로 저장
                    lastOp = c;
                }
            }
        }

        // 문제 조건: C가 없는 경우는 없다고 가정하거나, 출력 형식에 맞춤
        if(!printed) {
            bw.write("NO OUTPUT");
        }

        bw.flush();
        bw.close();
    }

    // 계산 로직 분리
    public static int calc(int a, char op, int b) {
        switch (op) {
            case 'S': return a - b;
            case 'M': return a * b;
            case 'U': return a / b; // 정수 나눗셈
            case 'P': return a + b;
        }
        return a;
    }
}