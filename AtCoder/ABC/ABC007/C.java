import java.util.ArrayDeque;
import java.util.Deque;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class C {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String[] rc = br.readLine().split(" ");
    int r = Integer.parseInt(rc[0]);
    int c = Integer.parseInt(rc[1]);
    int[][] grid = new int[r][c];
    int[][] distance = new int[r][c];
    boolean[][] visited = new boolean[r][c];
    String[] start = br.readLine().split(" ");
    int sy = Integer.parseInt(start[0]) - 1;
    int sx = Integer.parseInt(start[1]) - 1;
    String[] goal = br.readLine().split(" ");
    int gy = Integer.parseInt(goal[0]) - 1;
    int gx = Integer.parseInt(goal[1]) - 1;
    int[][] df = { { 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 } };
  }
}
