import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] color = {"black", "brown", "red","orange","yellow",
                "green", "blue","violet","grey","white"};
        List<String> colors = Arrays.asList(color);
        
        String omColor1 = br.readLine();
        String omColor2 = br.readLine();
        String multiColor = br.readLine();

        int index1 = colors.indexOf(omColor1);
        int index2 = colors.indexOf(omColor2);
        int index3 = colors.indexOf(multiColor);
        
        long value = (index1 * 10L) + index2;
        long result = value * (long)Math.pow(10,index3);

        bw.write(result+"");
        bw.flush();
        bw.close();
    }
}
