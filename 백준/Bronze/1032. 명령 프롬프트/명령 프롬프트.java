import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        String result = "";
        List<String> words = new ArrayList<String>();
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            words.add(s);
        }

        if (words.size() == 1) {
            bw.write(words.get(0));
            bw.flush();
            bw.close();
            System.exit(0);
        }
        for (int i = 0; i < words.get(0).length(); i++) {
            boolean equal = true;
            char c = words.get(0).charAt(i);
            for (int j = 1; j < n; j++) {
                if (words.get(j).charAt(i) != c) {
                    equal = false;
                    break;
                }
            }
            if(equal) {
                result += words.get(0).charAt(i);
            }
            else {
                result += '?';
            }
        }

        bw.write(result);
        bw.flush();
        bw.close();
    }
}
