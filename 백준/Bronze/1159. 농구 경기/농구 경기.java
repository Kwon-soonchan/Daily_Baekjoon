import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] firstName = new int[26];
        int n = Integer.parseInt(br.readLine());

        for(int i=0;i<n;i++) {
            String s = br.readLine();
            firstName[s.charAt(0)-'a']++;
        }
        
        StringBuilder result = new StringBuilder();
        for(int i=0;i<firstName.length;i++) {
            if(firstName[i] >= 5) {
                result.append((char)('a'+i));
            }
        }
        
        if(result.length() == 0) {
            bw.write("PREDAJA");
        }
        else {
            bw.write(result.toString());
        }
        bw.flush();
        bw.close();
    }
}
