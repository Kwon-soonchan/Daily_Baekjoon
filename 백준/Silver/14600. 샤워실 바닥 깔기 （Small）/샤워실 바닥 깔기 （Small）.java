import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int[][] map;
    static int cnt = 0; // 타일 번호

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int K = Integer.parseInt(br.readLine());
        int N = (int) Math.pow(2, K); // 격자 크기

        map = new int[N][N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());

        // 좌표 변환: (왼쪽 아래 1,1) -> (왼쪽 위 0,0 기준 배열 인덱스)
        // 행: N - y, 열: x - 1
        int holeR = N - y;
        int holeC = x - 1;

        map[holeR][holeC] = -1; // 배수구 표시

        // 분할 정복 시작
        solve(0, 0, N);

        // 출력
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                bw.write(map[i][j] + " ");
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }

    // (r, c)는 현재 사각형의 왼쪽 위 좌표, size는 현재 사각형의 한 변의 길이
    static void solve(int r, int c, int size) {
        if (size == 1) return; // 더 이상 쪼갤 수 없으면 종료

        int half = size / 2;
        cnt++; // 중앙에 놓을 타일의 번호 증가
        int currentTileNum = cnt; // 현재 단계의 타일 번호 저장

        // 1. 왼쪽 위 사분면 (Top-Left)
        // 구멍이 이 사분면에 있는지 확인
        if (check(r, c, half)) {
            // 구멍이 있으면 재귀 호출 (구멍은 그대로 둠)
            solve(r, c, half);
        } else {
            // 구멍이 없으면, 이 사분면의 '오른쪽 아래'를 채우고 거기를 구멍으로 침
            map[r + half - 1][c + half - 1] = currentTileNum;
            solve(r, c, half);
        }

        // 2. 오른쪽 위 사분면 (Top-Right)
        if (check(r, c + half, half)) {
            solve(r, c + half, half);
        } else {
            // 구멍이 없으면 '왼쪽 아래'를 채움
            map[r + half - 1][c + half] = currentTileNum;
            solve(r, c + half, half);
        }

        // 3. 왼쪽 아래 사분면 (Bottom-Left)
        if (check(r + half, c, half)) {
            solve(r + half, c, half);
        } else {
            // 구멍이 없으면 '오른쪽 위'를 채움
            map[r + half][c + half - 1] = currentTileNum;
            solve(r + half, c, half);
        }

        // 4. 오른쪽 아래 사분면 (Bottom-Right)
        if (check(r + half, c + half, half)) {
            solve(r + half, c + half, half);
        } else {
            // 구멍이 없으면 '왼쪽 위'를 채움
            map[r + half][c + half] = currentTileNum;
            solve(r + half, c + half, half);
        }
    }

    // 해당 영역(r, c 부터 size만큼)에 0이 아닌 값(배수구 -1 이나 이미 채워진 타일)이 있는지 확인
    static boolean check(int r, int c, int size) {
        for (int i = r; i < r + size; i++) {
            for (int j = c; j < c + size; j++) {
                if (map[i][j] != 0) {
                    return true;
                }
            }
        }
        return false;
    }
}