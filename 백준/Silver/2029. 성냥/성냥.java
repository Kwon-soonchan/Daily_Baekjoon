import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 보드 입력
        char[][] board = new char[10][10];
        for (int i = 0; i < 10; i++) {
            String garo = br.readLine();
            for (int j = 0; j < 10; j++) {
                board[i][j] = garo.charAt(j);
            }
        }

        int cnt = 0;
        // 가로찾기
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '-' && board[i][j + 1] == '-') {
                    cnt++;
                }
            }
        }
        // 세로찾기
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 10; j++) {
                if (board[i][j] == '|' && board[i + 1][j] == '|') {
                    cnt++;
                }
            }
        }

        int A = 24 - cnt;
        int B = 0;

        // 정사각형 구하기(1짜리 2짜리 3짜리 다 돌기)
        for (int i = 1; i <= 3; i++) {
            for (int j = 0; j <= 3 - i; j++) {
                for (int k = 0; k <= 3 - i; k++) {
                    boolean check = true;
                    
                    for (int l = 0; l < i; l++) {
                        if (board[j * 3][(k + l) * 3 + 1] != '-') {
                            check = false;
                            break;
                        }

                        if (board[(j + i) * 3][(k + l) * 3 + 1] != '-') {
                            check = false;
                            break;
                        }

                        if (board[(j + l) * 3 + 1][k * 3] != '|') {
                            check = false;
                            break;
                        }

                        if (board[(j + l) * 3 + 1][(k + i) * 3] != '|') {
                            check = false;
                            break;
                        }
                    }
                    if(check) {
                        B++;
                    }
                }
            }
        }

        bw.write(A + " " + B);
        bw.flush();
        bw.close();
    }
}
