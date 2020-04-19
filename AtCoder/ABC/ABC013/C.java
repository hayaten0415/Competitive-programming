import java.util.*;
import java.io.*;
import java.math.*;

public class C {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long n = sc.nextLong();
    int N = (int) n;
    long h = sc.nextLong();
    int H = (int) h;
    long a = sc.nextLong();
    long b = sc.nextLong();
    int B = (int) b;
    long c = sc.nextLong();
    long d = sc.nextLong();
    int D = (int) d;
    int e = sc.nextInt();
    int lifeMax = (int)(h + n * b);

    long[][] dp = new long[N + 1][lifeMax + 1];
    for (int i = 0; i < n + 1; i++) {
      for (int j = 0; j < lifeMax; j++) {
        dp[i][j] = Long.MAX_VALUE / 2;
      }
    }
    //0日目の満腹度
    dp[0][H] = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 1; j < lifeMax; j++) {
        if (i + 1 <= N) {
          //普通の食事
          if (j + b < lifeMax) {
            dp[i + 1][j + 1] = Math.min(dp[i + 1][j + B], dp[i][j] + a);
          }
          //質素な食事
          if (j + d < lifeMax) {
            dp[i + 1][j + 1] = Math.min(dp[i + 1][j + D], dp[i][j] + c);
          }
          //食べない
          if (j - e > 0) {
            dp[i + 1][j + 1] = Math.min(dp[i + 1][j - e], dp[i][j] + 0);
          }
        }
      }
    }
    long min = Long.MAX_VALUE / 2;
    for (int j = 1; j < lifeMax; j++) {
      min = Math.min(min, dp[N][j]);
    }
    System.out.println(min);
  }
}