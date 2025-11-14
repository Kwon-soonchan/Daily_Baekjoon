import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());

        for(int i = 0; i < t; i++) {
            String nums = br.readLine();
            List<Integer> numList = new ArrayList<Integer>();

            for(int j = 0; j < nums.length(); j++) {
                if(nums.charAt(j) == '6') {
                    numList.add(9);
                }
                else {
                    numList.add(nums.charAt(j) - '0');
                }
            }

            Collections.sort(numList, Collections.reverseOrder());

            long num1 = 0;
            long num2 = 0;

            for (int digit : numList) {
                if (num1 <= num2) {
                    num1 = num1 * 10 + digit;
                } else {
                    num2 = num2 * 10 + digit;
                }
            }

            long result = num1 * num2;
            bw.write(result + "\n");
        }

        bw.flush();
        bw.close();
    }
}