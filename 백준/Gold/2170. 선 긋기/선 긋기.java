import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        List<int[]> dotList = new ArrayList<>();
        List<int[]> resultList = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            dotList.add(new int[]{x, y});
        }

        Collections.sort(dotList, (a, b) -> a[0] - b[0]);
        resultList.add(dotList.get(0));

        for (int i = 1; i < n; i++) {
            int[] lastLine = resultList.get(resultList.size()-1);
            if (lastLine[1] < dotList.get(i)[0]) {
                resultList.add(dotList.get(i));
            } else {
                if (lastLine[1] < dotList.get(i)[1]) {
                    lastLine[1] = dotList.get(i)[1];
                }
            }
        }

        int result = 0;
        for (int[] i : resultList) {
            result += i[1] - i[0];
        }

        bw.write(result + "");
        bw.flush();
        bw.close();
    }
}
