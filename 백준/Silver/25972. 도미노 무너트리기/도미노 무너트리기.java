import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        Domino[] domino = new Domino[n];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());
            domino[i] = new Domino(a, l);
        }

        Arrays.sort(domino, new Comparator<Domino>() {
            @Override
            public int compare(Domino d1, Domino d2) {
                return Integer.compare(d1.a, d2.a);
            }
        });

        int cnt = 1;

        for (int i = 0; i < n - 1; i++) {
            if ((domino[i].a + domino[i].l) < domino[i + 1].a) {
                cnt++;
            }
        }
        bw.write(cnt + "");
        bw.flush();
        bw.close();
    }
}

class Domino {
    int a;
    int l;

    public Domino(int a, int l) {
        this.a = a;
        this.l = l;
    }
}