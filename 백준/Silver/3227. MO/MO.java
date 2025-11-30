import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    static int[] board;
    static int P;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        P = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        board = new int[P];

        // true: White(1), false: Black(2)
        boolean isWhiteTurn = true;

        for (int i = 0; i < n; i++) {
            int pos = Integer.parseInt(br.readLine()) - 1;
            int myColor = isWhiteTurn ? 1 : 2;
            int opColor = isWhiteTurn ? 2 : 1;

            board[pos] = myColor;
            checkAndRemove(pos, myColor, opColor, -1);
            checkAndRemove(pos, myColor, opColor, 1);
            isWhiteTurn = !isWhiteTurn;
        }

        int whiteCnt = 0;
        int blackCnt = 0;
        for (int i = 0; i < P; i++) {
            if (board[i] == 1) whiteCnt++;
            else if (board[i] == 2) blackCnt++;
        }

        bw.write(whiteCnt + " " + blackCnt);
        bw.flush();
        bw.close();
    }

    static void checkAndRemove(int start, int myColor, int opColor, int dir) {
        int curr = start + dir;
        int countOp = 0;

        while (curr >= 0 && curr < P) {

            if (board[curr] == 0) {
                return;
            }

            if (board[curr] == myColor) {
                if (countOp > 0) {
                    removeStones(start, curr, dir);
                }
                return;
            }

            countOp++;
            curr += dir;
        }
    }

    static void removeStones(int start, int end, int dir) {
        int curr = start + dir;
        while (curr != end) {
            board[curr] = 0;
            curr += dir;
        }
    }
}