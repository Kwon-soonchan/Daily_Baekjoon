import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int q = Integer.parseInt(br.readLine());

        for (int i = 0; i < q; i++) {
            int n = Integer.parseInt(br.readLine());
            String sub = "";
            boolean check = true;

            if (n == 1) {
                check = false;
                br.readLine();
            } else {
                StringTokenizer st = new StringTokenizer(br.readLine());

                for (int j = 0; j < n; j++) {
                    String station = st.nextToken();

                    if (station.length() > 4) {
                        check = false;
                        break;
                    } else {
                        String curSub = station.substring(station.length() - 2);
                        if (j != 0) {
                            if (!sub.equals(curSub)) {
                                check = false;
                                break;
                            }
                        }
                        sub = curSub;
                    }
                }
            }

            if (check) {
                bw.write("YES\n");
            } else {
                bw.write("NO\n");
            }
        }

        bw.flush();
        bw.close();
    }
}
