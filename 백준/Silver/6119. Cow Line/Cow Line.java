import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int cowNum = 1;
        Deque<Integer> d = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String command = st.nextToken();
            if (command.equals("A")) {
                String dir = st.nextToken();
                if (dir.equals("L")) {
                    d.addFirst(cowNum);
                    cowNum++;
                } else {
                    d.addLast(cowNum);
                    cowNum++;
                }
            } else {
                String dir = st.nextToken();
                if (dir.equals("L")) {
                    int cnt = Integer.parseInt(st.nextToken());
                    for (int j = 0; j < cnt; j++) {
                        d.removeFirst();
                    }
                } else {
                    int cnt = Integer.parseInt(st.nextToken());
                    for (int j = 0; j < cnt; j++) {
                        d.removeLast();
                    }
                }
            }
        }
        int size = d.size();
        for (int i = 0; i < size; i++) {
            bw.write(d.getFirst() + "\n");
            d.removeFirst();
        }
        bw.flush();
        bw.close();
    }
}
