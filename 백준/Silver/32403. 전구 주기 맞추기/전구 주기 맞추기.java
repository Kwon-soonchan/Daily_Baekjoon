import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()); // 전구 개수
        int t = Integer.parseInt(st.nextToken()); // 목표 시간

        // 1. T의 모든 약수를 구합니다.
        List<Integer> divisors = new ArrayList<>();
        for (int i = 1; i * i <= t; i++) {
            if (t % i == 0) {
                divisors.add(i);
                // i*i가 t가 아닐 때만 (t/i)를 추가 (e.g., t=16일 때 4 중복 방지)
                if (i * i != t) {
                    divisors.add(t / i);
                }
            }
        }

        st = new StringTokenizer(br.readLine()); // 두 번째 줄 (전구 주기) 읽기
        int totalCost = 0; // 총 조작 횟수

        // 2. N개의 전구를 하나씩 확인합니다.
        for (int i = 0; i < n; i++) {
            int currentPeriod = Integer.parseInt(st.nextToken()); // 현재 전구의 주기

            int minCostForThisBulb = Integer.MAX_VALUE; // 이 전구의 최소 조작 횟수

            // 3. T의 약수 리스트를 보며, 현재 주기와 가장 가까운 약수를 찾습니다.
            for (int d : divisors) {
                int cost = Math.abs(currentPeriod - d);
                minCostForThisBulb = Math.min(minCostForThisBulb, cost);
            }

            // 4. 이 전구의 최소 비용을 총합에 더합니다.
            totalCost += minCostForThisBulb;
        }

        // 5. 최종 결과를 출력합니다.
        bw.write(totalCost + "");
        bw.flush();
        bw.close();
    }
}