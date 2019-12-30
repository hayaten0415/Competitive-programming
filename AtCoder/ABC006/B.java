import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    long ans[] = new long[1000000];
    ans[0] = 0;
    ans[1] = 0;
    ans[2] = 1;
    for (int i = 3; i < 1000000; i++) {
      ans[i] = (ans[i - 1] + ans[i - 2] + ans[i - 3]) % 10007;
    }

    System.out.println(ans[n-1]);
  }
}
