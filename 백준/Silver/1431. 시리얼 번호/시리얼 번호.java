import java.io.*;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        Serial[] arr = new Serial[n];

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            arr[i] = new Serial(s);
        }

        Arrays.sort(arr);

        for (int i = 0; i < n; i++) {
            bw.write(arr[i].s + "\n");
        }
        bw.flush();
        bw.close();
    }
}

class Serial implements Comparable<Serial> {
    String s;

    public Serial(String s) {
        this.s = s;
    }

    private int getSum(String s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c >= '0' && c <= '9') {
                sum += c - '0';
            }
        }
        return sum;
    }

    @Override
    public int compareTo(Serial o) {
        // 길이가 짧은게 먼저
        if (this.s.length() != o.s.length()) {
            return this.s.length() - o.s.length();
        }
        // 길이가 같으면 숫자합이 작은게 먼저
        int thisSum = getSum(this.s);
        int oSum = getSum(o.s);
        if (thisSum != oSum) {
            return thisSum - oSum;
        }
        // 마지막은 사전순
        return this.s.compareTo(o.s);
    }
}