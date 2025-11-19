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

    static class Point {
        int x, y, id;

        public Point(int x, int y, int id) {
            this.x = x;
            this.y = y;
            this.id = id;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        List<Point> cowList = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            cowList.add(new Point(x, y, i + 1));
        }

        double maxC = 0;
        int id1 = 0;
        int id2 = 0;

        for (int i = 0; i < n - 1; i++) {
            Point p1 = cowList.get(i);
            int ix = p1.x;
            int iy = p1.y;
            int iid = p1.id;
            for (int j = i + 1; j < n; j++) {
                Point p2 = cowList.get(j);
                int jx = p2.x;
                int jy = p2.y;
                int jid = p2.id;

                double c = Math.sqrt(Math.pow((jx - ix), 2) + Math.pow((jy - iy), 2));
                if (maxC < c) {
                    maxC = c;
                    id1 = iid;
                    id2 = jid;
                }

            }
        }

        bw.write(id1 + " " + id2);
        bw.flush();
        bw.close();
    }
}
