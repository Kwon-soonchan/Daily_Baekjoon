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

        String yeondu = br.readLine();
        int teamNumber = Integer.parseInt(br.readLine());

        int[] yeonduCount = new int[26];
        for (int i = 0; i < yeondu.length(); i++) {
            yeonduCount[yeondu.charAt(i) - 'A']++;
        }

        int maxPoint = -1;
        String winner = "";

        for (int i = 0; i < teamNumber; i++) {
            String teamName = br.readLine();
            int[] teamNameCount = new int[26];
            for (int j = 0; j < teamName.length(); j++) {
                teamNameCount[teamName.charAt(j) - 'A']++;
            }

            int L = yeonduCount['L' - 'A'] + teamNameCount['L' - 'A'];
            int O = yeonduCount['O' - 'A'] + teamNameCount['O' - 'A'];
            int V = yeonduCount['V' - 'A'] + teamNameCount['V' - 'A'];
            int E = yeonduCount['E' - 'A'] + teamNameCount['E' - 'A'];

            int point = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;

            if (point > maxPoint) {
                maxPoint = point;
                winner = teamName;
            } else if (point == maxPoint) {
                if (winner.equals("") || teamName.compareTo(winner) < 0) {
                    winner = teamName;
                }
            }
        }

        bw.write(winner);
        bw.flush();
        bw.close();
        br.close();

    }
}
