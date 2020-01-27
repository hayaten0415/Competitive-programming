import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int bug_softs = 0;
    int bugs = 0;
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
    }
    Arrays.sort(a);
    for (int i = 0; i < n; i++) {
      if (a[i] == 0)
        continue;
      bugs += a[i];
      bug_softs++;
    }
    int ans = (int) Math.ceil((double) bugs / (double) bug_softs);
    System.out.println(ans);
  }
}
