import java.util.Scanner;
import java.util.Arrays;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int h = sc.nextInt();
    int n = sc.nextInt();
    boolean condition = false;
    int[] T = new int[n];
    for (int i = 0; i < n; i++) {
      h -= sc.nextInt();
      if (h <= 0) {
        condition = true;
        break;
      }
    }
    System.out.println(condition? "Yes":"No");
  }
}