import java.util.Scanner;
import java.util.Arrays;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int k = sc.nextInt();
    double ans = 0;
    int[] rate = new int[n];
    for (int i = 0; i < n; i++) {
      rate[i] = sc.nextInt();
    }
    Arrays.sort(rate);
    for (int i = n - k; i < n; i++) {
      ans = (ans + (double) rate[i]) / 2;
    }
    System.out.println(ans);
  }
}
