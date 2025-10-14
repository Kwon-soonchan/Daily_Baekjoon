import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s = br.readLine();
        StringTokenizer st = new StringTokenizer(s);
        int king = Integer.parseInt(st.nextToken());
        int queen = Integer.parseInt(st.nextToken());
        int rook = Integer.parseInt(st.nextToken());
        int bishop = Integer.parseInt(st.nextToken());
        int knight = Integer.parseInt(st.nextToken());
        int pon = Integer.parseInt(st.nextToken());
        int[] change = {0,0,0,0,0,0};

        if(king > 1) {
            while(king != 1) {
                king--;
                change[0]--;
            }
        }
        else {
            while(king != 1) {
                king++;
                change[0]++;
            }
        }
        if(queen > 1) {
            while(queen != 1) {
                queen--;
                change[1]--;
            }
        }
        else {
            while(queen != 1) {
                queen++;
                change[1]++;
            }
        }
        if(rook > 2) {
            while(rook != 2) {
                rook--;
                change[2]--;
            }
        }
        else {
            while(rook != 2) {
                rook++;
                change[2]++;
            }
        }
        if(bishop > 2) {
            while(bishop != 2) {
                bishop--;
                change[3]--;
            }
        }
        else {
            while(bishop != 2) {
                bishop++;
                change[3]++;
            }
        }
        if(knight > 2) {
            while(knight != 2) {
                knight--;
                change[4]--;
            }
        }
        else {
            while(knight != 2) {
                knight++;
                change[4]++;
            }
        }
        if(pon > 8) {
            while(pon != 8) {
                pon--;
                change[5]--;
            }
        }
        else {
            while(pon != 8) {
                pon++;
                change[5]++;
            }
        }

        bw.write(change[0] + " ");
        bw.write(change[1] + " ");
        bw.write(change[2] + " ");
        bw.write(change[3] + " ");
        bw.write(change[4] + " ");
        bw.write(change[5] + " ");
        bw.flush();
        bw.close();
    }
}
