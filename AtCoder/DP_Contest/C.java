import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[][] nums = new int[n][3];
    int[][] dp = new int[n][3];
    int max = 0;
    for (int i = 0; i < n; i++) {
      //a列
      nums[i][0] = sc.nextInt();
      //b列
      nums[i][1] = sc.nextInt();
      //c列
      nums[i][2] = sc.nextInt();
    }
    sc.close();
    dp[0][0] = nums[0][0];
    dp[0][1] = nums[0][1];
    dp[0][2] = nums[0][2];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 3; j++) {
        for (int j2 = 0; j2 < 3; j2++) {
          if (j == j2) {
            continue;
          } else {
            if (i + 1 < n) {
              dp[i + 1][j2] = Math.max(dp[i + 1][j2], dp[i][j] + nums[i][j2]);
            }
          }
        }
      }
    }
    for (int i = 0; i < 3; i++) {
      max = Math.max(max, dp[n - 1][i]);
    }
    System.out.println(max);
  }
}