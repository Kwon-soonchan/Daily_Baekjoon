import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        Deque<Integer> dq = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            dq.add(i + 1);
        }

        StringTokenizer target = new StringTokenizer(br.readLine());
        int[] targetList = new int[m];
        for (int i = 0; i < m; i++) {
            targetList[i] = Integer.parseInt(target.nextToken());
        }

        int totalCnt = 0;

        for (int i = 0; i < m; i++) {
            int targetIdx = ((LinkedList<Integer>) dq).indexOf(targetList[i]);
            int leftCost = targetIdx;
            int rightCost = dq.size() - targetIdx;

            if (leftCost <= rightCost) {
                for (int j = 0; j < leftCost; j++) {
                    dq.addLast(dq.pollFirst());
                }
                totalCnt += leftCost;
            } else {
                for (int j = 0; j < rightCost; j++) {
                    dq.addFirst(dq.pollLast());
                }
                totalCnt += rightCost;
            }

            dq.pollFirst();
        }

        bw.write(totalCnt + "");
        bw.flush();
        bw.close();
    }
}
