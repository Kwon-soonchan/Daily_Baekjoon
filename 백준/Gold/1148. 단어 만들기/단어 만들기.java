import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class Main {
    static class Word {
        int[] cnt = new int[26];

        public Word(String s) {
            for (char c : s.toCharArray()) {
                cnt[c - 'A']++;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        List<Word> words = new ArrayList<>();
        int[] alphabet = new int[26];
        while (true) {
            String line = br.readLine();
            if (line.equals("-")) {
                break;
            }
            words.add(new Word(line));
        }

        while (true) {
            String board = br.readLine();
            if (board.equals("#")) {
                break;
            }

            int[] boardCnt = new int[26];
            for (char c : board.toCharArray()) {
                boardCnt[c - 'A']++;
            }

            int[] result = new int[26];

            for (Word word : words) {
                boolean possible = true;
                for (int i = 0; i < 26; i++) {
                    if (word.cnt[i] > boardCnt[i]) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    for (int i = 0; i < 26; i++) {
                        if (word.cnt[i] > 0) {
                            result[i]++;
                        }
                    }
                }
            }

            int minCnt = Integer.MAX_VALUE;
            int maxCnt = -1;

            for (int i = 0; i < 26; i++) {
                if (boardCnt[i] > 0) {
                    if (result[i] < minCnt) {
                        minCnt = result[i];
                    }
                    if (result[i] > maxCnt) {
                        maxCnt = result[i];
                    }
                }
            }

            StringBuilder minChars = new StringBuilder();
            StringBuilder maxChars = new StringBuilder();

            for (int i = 0; i < 26; i++) {
                if (boardCnt[i] > 0) {
                    if (result[i] == minCnt) {
                        minChars.append((char) ('A' + i));
                    }
                    if (result[i] == maxCnt) {
                        maxChars.append((char) ('A' + i));
                    }
                }
            }
            bw.write(minChars.toString() + " " + minCnt + " " + maxChars.toString() + " " + maxCnt + "\n");
        }
        bw.flush();
        bw.close();
    }
}
