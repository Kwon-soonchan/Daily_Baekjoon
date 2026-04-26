import java.io.*;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        int[] arr2 = new int[n];
        
        for(int i = 0; i < n; i++){
            int num = Integer.parseInt(br.readLine());
            arr[i] = num;
            arr2[i] = num;
        }
        
        Arrays.sort(arr2);
        
        if(arr[0] == arr2[0]) {
            bw.write("ez");
        }
        else if(arr[0] == arr2[n-1]) {
            bw.write("hard");
        }
        else {
            bw.write("?");
        }
        bw.flush();
        bw.close();
    }
}
