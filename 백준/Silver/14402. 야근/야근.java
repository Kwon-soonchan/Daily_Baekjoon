import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int q = Integer.parseInt(br.readLine());

        HashMap<String, Integer> member = new HashMap<>();
        int cnt = 0;

        for (int i = 0; i < q; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            String inout = st.nextToken();

            if (inout.equals("+")) {
                member.put(name, member.getOrDefault(name, 0) + 1);
            } else {
                int currentCount = member.getOrDefault(name, 0);

                if (currentCount > 0) {
                    member.put(name, currentCount - 1);
                } else {
                    cnt++;
                }
            }
        }

        for (String key : member.keySet()) {
            cnt += member.get(key);
        }

        bw.write(cnt + "");
        bw.flush();
        bw.close();
    }
}