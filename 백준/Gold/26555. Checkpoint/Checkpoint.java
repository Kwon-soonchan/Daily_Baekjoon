import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static class Point {
        int r, c, d;

        public Point(int r, int c, int d) {
            this.r = r;
            this.c = c;
            this.d = d;
        }
    }

    static int R, C, D;
    static char[][] board;
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            R = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());
            D = Integer.parseInt(st.nextToken());
            board = new char[R][C];
            Point[] targets = new Point[D + 2];

            for (int j = 0; j < R; j++) {
                String line = br.readLine();
                for (int k = 0; k < C; k++) {
                    board[j][k] = line.charAt(k);
                    if (board[j][k] == 'S') {
                        targets[0] = new Point(j, k, 0);
                    } else if (board[j][k] == 'E') {
                        targets[D + 1] = new Point(j, k, 0);
                    } else if (Character.isDigit(board[j][k])) {
                        int idx = board[j][k] - '0';
                        targets[idx] = new Point(j, k, 0);
                    }
                }
            }
            long total = 0;
            boolean possible = true;

            for (int j = 0; j < D + 1; j++) {
                int dist = bfs(targets[j], targets[j + 1]);
                if (dist == -1) {
                    possible = false;
                    break;
                }
                total += dist;
            }

            if (possible) {
                bw.write(total + "\n");
            }
        }
        bw.flush();
        bw.close();
    }

    static int bfs(Point start, Point end) {
        boolean[][] visited = new boolean[R][C];
        Queue<Point> q = new LinkedList<>();

        q.add(new Point(start.r, start.c, 0));
        visited[start.r][start.c] = true;

        while (!q.isEmpty()) {
            Point cur = q.poll();

            if (cur.r == end.r && cur.c == end.c) {
                return cur.d;
            }

            for (int i = 0; i < 4; i++) {
                int nr = cur.r + dr[i];
                int nc = cur.c + dc[i];

                if (nr >= 0 && nc >= 0 && nr < R && nc < C) {
                    if (!visited[nr][nc] && board[nr][nc] != '#') {
                        visited[nr][nc] = true;
                        q.add(new Point(nr, nc, cur.d + 1));
                    }
                }
            }
        }
        return -1;
    }
}
