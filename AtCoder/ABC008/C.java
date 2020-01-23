import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int nums[] = new int[n];
    for (int i = 0; i < n; i++) {
      nums[i] = sc.nextInt();
    }
    //各コインの約数を調べる
    int divisor_cnt[] = new int[n];
    for (int i = 0; i < n; i++) {
      int current = nums[i];
      for (int j = 0; j < n; j++) {
        if (i == j) {
          continue;
        }
        if (current % nums[j] == 0) {
          divisor_cnt[i]++;
        }
      }
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
      int s = divisor_cnt[i];
      double a;
      if (s % 2 == 0) {
        a = ((double) s / 2 + 1) / (s + 1);
      } else {
        a = (double)1 / 2;
      }
      ans += a;
    }
    System.out.println(ans);
  }
}