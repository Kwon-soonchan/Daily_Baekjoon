import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger; // BigInteger import

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        BigInteger result = factorial(1, n);

        bw.write(result.toString());
        bw.flush();
        bw.close();
    }

    public static BigInteger factorial(int from, int to) {
        if (from == to) {
            return BigInteger.valueOf(from);
        }

        if (from > to) {
            return BigInteger.ONE;
        }

        int mid = (from + to) / 2;

        BigInteger left = factorial(from, mid);
        BigInteger right = factorial(mid + 1, to);

        return left.multiply(right);
    }
}