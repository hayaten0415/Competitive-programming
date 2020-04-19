import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] nums = new int[n];
    int[] dp = new int[n];
    for (int i = 0; i < n; i++) {
      nums[i] = sc.nextInt();
    }
    Arrays.fill(dp, 1000000);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
      dp[i] = dp[i - 1] + Math.abs(nums[i] - nums[i - 1]);
      if (i > 1) {
        dp[i] = Math.min(dp[i], dp[i - 2] + Math.abs(nums[i] - nums[i - 2]));
      }
    }
    System.out.println(dp[n - 1]);
  }
}