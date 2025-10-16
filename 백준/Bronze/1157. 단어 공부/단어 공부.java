import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String word = br.readLine();
        String word_upper = word.toUpperCase();
        Integer[] alphabet_cnt_list = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        for (int i = 0; i < word.length(); i++) {
            alphabet_cnt_list[word_upper.charAt(i) - 'A']++;
        }
        int max_cnt = -1;
        int result = 0;
        for (int i = 0; i < alphabet_cnt_list.length; i++) {
            if (max_cnt == alphabet_cnt_list[i]) {
                result = '?';
            }
            else if (max_cnt < alphabet_cnt_list[i]) {
                max_cnt = alphabet_cnt_list[i];
                result = 'A'+i;
            }
        }
        bw.write(result);
        bw.flush();
        bw.close();
    }
}
