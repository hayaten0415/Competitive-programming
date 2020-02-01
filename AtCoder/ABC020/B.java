import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String a = sc.next();
    String b = sc.next();
    String str = a + b;
    int ans = Integer.parseInt(str) * 2;
    System.out.println(ans);
  }
}
