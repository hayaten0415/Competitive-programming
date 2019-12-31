import java.util.*;
import java.io.*;

public class D {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long a = sc.nextLong();
    long b = sc.nextLong();
    System.out.println(solve(b) - solve(a - 1));
  }

  static long solve(long a) {
    // dp[ 決めた桁数 ][ 未満フラグ ][4 or 9] := 総数
    long[][][] dp = new long[100][2][2];
    dp[0][0][0] = 1;
    String str = String.valueOf(a);
    int length = str.length();
    int range_digit = 9;
    for (int i = 0; i < length; i++) {
      int max_digit = Character.getNumericValue(str.charAt(i));
      for (int flag_less = 0; flag_less < 2; flag_less++) {
        for (int flag_four_or_nine = 0; flag_four_or_nine < 2; flag_four_or_nine++) {
          if (flag_less == 1) {
            range_digit = 9;
          } else {
            range_digit = max_digit;
          }
          for (int d = 0; d < range_digit + 1; d++) {
            int flag_less_next = 0;
            int flag_four_or_nine_next = 0;
            if (flag_less == 1 || d < max_digit) {
              flag_less_next = 1;
            }
            if (flag_four_or_nine == 1 || d == 4 || d == 9) {
              flag_four_or_nine_next = 1;
            }
            dp[i + 1][flag_less_next][flag_four_or_nine_next] += dp[i][flag_less][flag_four_or_nine];
          } 
        }
      }
    }
    return dp[length][0][1] + dp[length][1][1];
  }
}