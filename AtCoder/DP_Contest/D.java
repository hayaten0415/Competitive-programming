import java.util.*;

public class D {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int max_weight = sc.nextInt();
    int[] weight = new int[n];
    long[] value = new long[n];
    long max = 0;
    int start = 1;
    long[] dp = new long[max_weight + 1];
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      weight[i] = sc.nextInt();
      value[i] = sc.nextLong();
    }
    sc.close();
    for (int i = 0; i < max_weight + 1; i++) {
      for (int j = 0; j < n; j++) {
        if (i + weight[j] < max_weight + 1) {
          dp[i + weight[j]] = Math.max(dp[i + weight[j]], dp[i] + value[j]);
        }
      }
    }
    for (int i = 0; i < max_weight + 1; i++) {
      max = Math.max(max, dp[i]);
    }
    System.out.println(dp[max_weight]);
  }
}