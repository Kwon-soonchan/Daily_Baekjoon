import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        Score[] scores = new Score[n];

        for(int i = 0; i < n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            int k = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            scores[i] = new Score(name, k, e, m);
        }

        Arrays.sort(scores);
        
        for(int i = 0; i < n; i++){
            bw.write(scores[i].name + "\n");
        }
        bw.flush();
        bw.close();
    }
}

class Score implements Comparable<Score> {
    String name;
    int k;
    int e;
    int m;

    public Score(String name, int k, int e, int m) {
        this.name = name;
        this.k = k;
        this.e = e;
        this.m = m;
    }

    @Override
    public int compareTo(Score o) {
        // 국어점수가 다르면 내림차순
        if(this.k != o.k) {
            return o.k - this.k;
        }

        // 국어가 같고 영어가 다르면 오름차순
        if(this.e != o.e) {
            return this.e - o.e;
        }

        // 국,영 같고 수가 다르면 내림차순
        if(this.m != o.m) {
            return o.m - this.m;
        }

        // 다 똑같으면 이름 오름차순
        return this.name.compareTo(o.name);
    }
}
