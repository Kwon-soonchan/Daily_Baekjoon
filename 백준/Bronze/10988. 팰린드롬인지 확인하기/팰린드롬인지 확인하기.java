import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s = br.readLine();
        boolean check = true;

        for(int i=0; i<s.length()/2; i++) {
            if(s.charAt(i) == s.charAt(s.length()-1-i)) {
                continue;
            }
            else {
                check = false;
                break;
            }
        }

        if(check) {
            bw.write(1+"");
        }
        else {
            bw.write(0+"");
        }
        bw.flush();
        bw.close();
    }
}
