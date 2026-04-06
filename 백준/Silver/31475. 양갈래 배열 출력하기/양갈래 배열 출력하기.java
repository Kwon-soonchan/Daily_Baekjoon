import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] arr = new int[n][m];
        String s = br.readLine();

        // 상
        if (s.equals("U")) {
            // 하, 좌, 상, 우
            int[] dr = {1, 0, -1, 0};
            int[] dc = {0, -1, 0, 1};
            int dir = 0; // 처음엔 하(0) 방향으로 직진

            int r = 0;
            int c = m / 2;
            arr[r][c] = 1; // 시작칸
            int num = 2; // 다음칸
            int target = n * (m / 2 + 1); // 왼쪽 절반칸의 개수

            // 왼쪽 절반 칸 채우기
            while (num <= target) {
                // 다음 칸의 위치
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                // 갈 수 있으면?
                if (nr >= 0 && nr < n && nc >= 0 && nc <= m / 2 && arr[nr][nc] == 0) {
                    r = nr;
                    c = nc;
                    arr[r][c] = num++;
                } else {
                    dir = (dir + 1) % 4;
                }
            }

            // 오른쪽 절반 채우기
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m / 2; j++) {
                    arr[i][m - 1 - j] = arr[i][j];
                }
            }

            // 출력
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    bw.write(arr[i][j] + " ");
                }
                bw.write("\n");
            }
        }

        // 하
        else if (s.equals("D")) {
            // 상, 좌, 하, 우
            int[] dr = {-1, 0, 1, 0};
            int[] dc = {0, -1, 0, 1};
            int dir = 0; // 처음엔 상(0) 방향으로 직진

            int r = n - 1;
            int c = m / 2;
            arr[r][c] = 1; // 시작칸
            int num = 2; // 다음칸
            int target = n * (m / 2 + 1); // 왼쪽 절반칸의 개수

            // 왼쪽 절반 칸 채우기
            while (num <= target) {
                // 다음 칸의 위치
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                // 갈 수 있으면?
                if (nr >= 0 && nr < n && nc >= 0 && nc <= m / 2 && arr[nr][nc] == 0) {
                    r = nr;
                    c = nc;
                    arr[r][c] = num++;
                } else {
                    dir = (dir + 1) % 4;
                }
            }

            // 오른쪽 절반 채우기
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m / 2; j++) {
                    arr[i][m - 1 - j] = arr[i][j];
                }
            }

            // 출력
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    bw.write(arr[i][j] + " ");
                }
                bw.write("\n");
            }
        }

        // 좌
        else if (s.equals("L")) {
            // 우, 상, 좌, 하
            int[] dr = {0, -1, 0, 1};
            int[] dc = {1, 0, -1, 0};
            int dir = 0; // 처음엔 우(0) 방향으로 직진

            int r = n / 2;
            int c = 0;
            arr[r][c] = 1; // 시작칸
            int num = 2; // 다음칸
            int target = (n / 2 + 1) * m; // 위쪽 절반칸의 개수

            // 위쪽 절반 칸 채우기
            while (num <= target) {
                // 다음 칸의 위치
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                // 갈 수 있으면?
                if (nr >= 0 && nr <= n / 2 && nc >= 0 && nc < m && arr[nr][nc] == 0) {
                    r = nr;
                    c = nc;
                    arr[r][c] = num++;
                } else {
                    dir = (dir + 1) % 4;
                }
            }

            // 아래쪽 절반 채우기
            for (int i = 0; i < n / 2; i++) {
                for (int j = 0; j < m; j++) {
                    arr[n - 1 - i][j] = arr[i][j];
                }
            }

            // 출력
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    bw.write(arr[i][j] + " ");
                }
                bw.write("\n");
            }
        }

        // 우
        else if (s.equals("R")) {
            // 좌, 상, 우, 하
            int[] dr = {0, -1, 0, 1};
            int[] dc = {-1, 0, 1, 0};
            int dir = 0; // 처음엔 우(0) 방향으로 직진

            int r = n / 2;
            int c = m - 1;
            arr[r][c] = 1; // 시작칸
            int num = 2; // 다음칸
            int target = (n / 2 + 1) * m; // 위쪽 절반칸의 개수

            // 위쪽 절반 칸 채우기
            while (num <= target) {
                // 다음 칸의 위치
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                // 갈 수 있으면?
                if (nr >= 0 && nr <= n / 2 && nc >= 0 && nc < m && arr[nr][nc] == 0) {
                    r = nr;
                    c = nc;
                    arr[r][c] = num++;
                } else {
                    dir = (dir + 1) % 4;
                }
            }

            // 아래쪽 절반 채우기
            for (int i = 0; i < n / 2; i++) {
                for (int j = 0; j < m; j++) {
                    arr[n - 1 - i][j] = arr[i][j];
                }
            }

            // 출력
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    bw.write(arr[i][j] + " ");
                }
                bw.write("\n");
            }
        }

        bw.flush();
        bw.close();
    }
}
