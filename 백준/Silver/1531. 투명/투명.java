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
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] board = new int[101][101];

        for(int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            int lX = Integer.parseInt(st.nextToken());
            int lY = Integer.parseInt(st.nextToken());
            int rX = Integer.parseInt(st.nextToken());
            int rY = Integer.parseInt(st.nextToken());
            
            for(int j=lX;j<=rX;j++) {
                for(int k=lY;k<=rY;k++) {
                    board[j][k]++;
                }
            }
        }
        
        int count = 0;
        for(int i=1;i<=100;i++) {
            for(int j=1;j<=100;j++) {
                if(board[i][j] > m) {
                    count++;
                }
            }
        }
        
        bw.write(count+"");
        bw.flush();
        bw.close();
    }
}
