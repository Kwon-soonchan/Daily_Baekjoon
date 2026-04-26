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
    static class Mandarat implements Comparable<Mandarat> {
        String middle;
        List<String> details = new ArrayList<>();

        public Mandarat(String middle) {
            this.middle = middle;
        }

        @Override
        public int compareTo(Mandarat o) {
            return this.middle.compareTo(o.middle);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[][] goals = new String[9][9];
        for (int i = 0; i < 9; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 9; j++) {
                goals[i][j] = st.nextToken();
            }
        }

        List<Mandarat> blocks = new ArrayList<>();

        int[][] middles = {
                {1, 1}, {1, 4}, {1, 7},
                {4, 1}, {4, 7},
                {7, 1}, {7, 4}, {7, 7}
        };

        for (int[] middle : middles) {
            int r = middle[0];
            int c = middle[1];

            Mandarat block = new Mandarat(goals[r][c]);

            for (int i = r - 1; i <= r + 1; i++) {
                for (int j = c - 1; j <= c + 1; j++) {
                    if (i == r && j == c) {
                        continue;
                    }
                    block.details.add(goals[i][j]);
                }
            }

            Collections.sort(block.details);

            blocks.add(block);
        }
        Collections.sort(blocks);

        for (int i = 0; i < 8; i++) {
            Mandarat block = blocks.get(i);
            bw.write("#" + (i + 1) + ". " + block.middle + "\n");

            for (int j = 0; j < 8; j++) {
                bw.write("#" + (i + 1) + "-" + (j + 1) + ". " + block.details.get(j) + "\n");
            }
        }
        bw.flush();
        bw.close();
    }
}
