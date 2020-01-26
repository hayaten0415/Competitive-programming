import java.util.Scanner;
import java.util.Arrays;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] T = new int[n];
    for (int i = 0; i < n; i++) {
      T[i] = sc.nextInt();
    }
    Arrays.sort(T);
    System.out.println(T[0]);
  }
}