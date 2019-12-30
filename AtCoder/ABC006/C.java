import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    int a = 0;
    int b = 0;
    int c = 0;
    boolean condition = false;
    // mが偶数の場合
        // a + c = n と 2a + 4c = mの連立方程式を解くと
        // 以下のようにaとcは置ける
        a = (4 * n - m) / 2;
        c = n - a - b;
        if (2 * a + 3 * b + 4 * c == m && a >= 0 && b >= 0 && c >= 0) {
          condition = true;
        }
    // mが奇数の場合
    if (!condition) {
      b = 1;
      // a + c = n - 1と 2a + 4c = m - 3の連立方程式を解くと
      // 以下のようにおける
      a = (4 * n - m - 1) / 2;
      c = n - a - b;
      if (2 * a + 3 * b + 4 * c == m && a >= 0 && b >= 0 && c >= 0) {
        condition = true;
      }
    }
    
    System.out.println(condition? a + " " + b + " " + c : "-1 -1 -1");
  }
}
