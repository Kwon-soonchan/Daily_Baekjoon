import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());

        for(int i=0;i<t;i++) {
            int year = Integer.parseInt(br.readLine());
            int sum = 0;
            boolean check = true;
            for(int j=1;j<year;j++) {
                if(year%j==0) {
                    sum += j;
                    int sumK = 0;
                    for(int k=1;k<j;k++) {
                        if(j%k==0) {
                            sumK += k;
                        }
                    }
                    if(j < sumK) {
                        check = false;
                        break;
                    }
                }
            }
            if(year < sum) {
                if(check) {
                    bw.write("Good Bye\n");
                }
                else {
                    bw.write("BOJ 2022\n");
                }
            }
            else {
                bw.write("BOJ 2022\n");
            }
        }
        bw.flush();
        bw.close();
    }
}
